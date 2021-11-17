/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:48:27 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/17 21:51:27 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	threads_start(size_t count)
{
	t_philo	*tmp;
	t_table	table;
	size_t	i;

	table.philos = (t_philo **) malloc(count * sizeof(t_philo *));
	table.count = count;
	i = -1;
	while (++i < count)
	{
		table.philos[i] = (t_philo *) malloc(sizeof(t_philo));
		table.philos[i]->id = i;
		table.philos[i]->table = &table;
	}
	i = -1;
	while (++i < count)
		pthread_mutex_init(&(table.philos[i]->fork), NULL);
	i = -1;
	while (++i < count)
	{
		tmp = table.philos[i];
		pthread_create(&(tmp->thread), NULL, philo_take_fork, tmp);
	}
	return (table);
}

void	threads_wait(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->count)
	{
		pthread_join(table->philos[i]->thread, NULL);
		free(table->philos[i]);
		i++;
	}
	free(table->philos);
}
