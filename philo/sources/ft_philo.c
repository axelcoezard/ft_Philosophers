/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:47:57 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/24 16:38:41 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *philo, t_table *table, int index)
{
	philo->id = index + 1;
	philo->table = table;
	philo->sleeping = 0;
	philo->eating = 0;
	philo->last_eating = -1;
	philo->thinking = 0;
	philo->died = 0;

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
	size_t	i;

	philo = (t_philo *) data;
	i = -1;
	while (!philo->table->death)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	*philo_check_death(void *data)
{
	t_table	*table;
	size_t	i;

	table = (t_table *) data;
	while (!table->death)
	{
		i = -1;
		while (++i < table->count)
		{
			if (!table->philos[i].eating && time_get_millis_now() - \
			table->philos[i].last_eating >= table->time_to_die)
			{
				table->death = i + 1;
				break;
			}
		}
	}
	print(table->philos + (table->death - 1), HAS_DIED);
	return (NULL);
}
