/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:48:27 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/24 16:35:36 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	La fonction threads_create_all execute dans
 * 			l'ordre d'abord les threads des philosophes
 * 			d'indice pair puis ceux d'indice impair.
 *
 * @param	table	La structure t_table contenant les
 * 					philosophes.
 */
static void	threads_create_all(t_table *table)
{
	size_t	i;

	i = -1;
	while (++i < table->count)
	{
		if (i % 2 == 0)
			pthread_create(&table->philos[i].thread, NULL, \
				philo_routine, table->philos + i);
	}
	usleep(100);
	i = -1;
	while (++i < table->count)
	{
		if (i % 2 != 0)
			pthread_create(&table->philos[i].thread, NULL, \
				philo_routine, table->philos + i);
	}
}

/**
 * @brief	La fonction threads_start prepare tous les
 * 			mutex, philosophes et threads.
 *
 * @param	count	Le nombre de philosophe.
 *
 * @return	Une structure t_table contenenant les philosophes,
 * 			les fourchettes, et toutes les informations utiles.
 */
t_table	*threads_start(size_t count)
{
	t_table	*table;
	size_t	i;

	table = malloc(sizeof(t_table));
	table->count = count;
	table->time_to_eat = 800;
	table->time_to_sleep = 200;
	table->time_to_die = 200;
	table->death = 0;
	table->philos = malloc(count * sizeof(t_philo));
	table->forks = malloc(count * sizeof(pthread_mutex_t));
	table->time = time_get_now();
	pthread_mutex_init(&table->is_printing, NULL);
	i = -1;
	while (++i < count)
		philo_init(table->philos + i, table, i);
	i = -1;
	while (++i < count)
		philo_init_forks(table->philos + i, table, i);
	pthread_create(&table->is_diying, NULL, philo_check_death, table);
	threads_create_all(table);
	return (table);
}

/**
 * @brief	La fonction threads_wait attend la fin des threads
 * 			pour free(3) la memoire de t_table.
 *
 * @param	table	La structure t_table.
 */
void	threads_wait(t_table *table)
{
	size_t	i;

	pthread_join(table->is_diying, NULL);
	i = -1;
	while (++i < table->count)
	{
		pthread_join(table->philos[i].thread, NULL);
	}
	free(table->philos);
	free(table->forks);
	free(table);
}
