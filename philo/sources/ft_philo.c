/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:47:57 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/25 18:24:58 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *philo, t_table *table, int index)
{
	philo->id = index + 1;
	philo->table = table;
	philo->sleeping = 0;
	philo->eating = 0;
	philo->last_eat = time_get_millis_now();
	philo->n_eat = 0;
	philo->thinking = 0;
	pthread_mutex_init(table->forks + index, NULL);
}

void	philo_init_forks(t_philo *philo, t_table *table, int index)
{
	if (index - 1 < 0)
		philo->lfork = table->forks + (table->count - 1);
	else
		philo->lfork = table->forks + (index - 1);
	philo->rfork = table->forks + index;
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	while (1)
	{
		philo_eat(philo);
		if (philo->n_eat == 0)
			break;
		philo_sleep(philo);
		philo_think(philo);
		if (philo->table->death)
			break;
	}
	return (NULL);
}

size_t	philo_check_eat(t_table *table)
{
	size_t	i;

	i = -1;
	while (++i < table->count)
	{
		if (table->philos[i].n_eat < table->min_to_eat)
			return (0);
	}
	return (1);
}

void	*philo_check_death(void *data)
{
	t_table	*table;
	size_t	i;

	table = (t_table *) data;
	while (1)
	{
		i = -1;
		while (++i < table->count)
		{
			if (!table->philos[i].eating && time_get_millis_now() - \
			table->philos[i].last_eat >= table->time_to_die)
			{
				print(table->philos + i, HAS_DIED);
				table->death = 1;
				return (NULL);
			}
		}
		if (philo_check_eat(table))
			break;
	}
	return (NULL);
}
