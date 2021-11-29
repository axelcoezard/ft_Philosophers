/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:48:27 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/29 15:41:41 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief	La fonction threads_start prepare tous les
 * 			mutex, philosophes et threads.
 *
 * @param	table	La structure t_table contenant les
 * 					philosophes.
 *
 * @return	Une structure t_table contenenant les philosophes,
 * 			les fourchettes, et toutes les informations utiles.
 */
void	threads_start(t_table *table)
{
	size_t	i;

	table->is_printing = sem_open("printing", O_CREAT, O_RDWR, 1);
	table->forks = sem_open("forks", O_CREAT, O_RDWR, table->count);
	i = -1;
	while (++i < table->count)
		philo_init(table->philos + i, table, i);
	i = -1;
	while (++i < table->count)
	{
		pthread_create(&table->philos[i].thread, NULL, \
				philo_routine, table->philos + i);
	}
	philo_check_death(table);
}

/**
 * @brief	La fonction threads_wait attend la fin des threads
 * 			pour free(3) la memoire de t_table.
 *
 * @param	table	La structure t_table.
 */
void	threads_wait(t_table *table)
{
	sem_close(table->forks);
	sem_close(table->is_printing);
	sem_unlink("forks");
	sem_unlink("printing");
	free(table->philos);
	free(table);
}