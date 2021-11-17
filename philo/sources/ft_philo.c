/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:47:57 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/17 22:06:55 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO: #2 Fix le type d'argument de (t_philo *) à (void *)
void	*philo_take_fork(void *data)
{
	t_philo *philo;
	t_table	*table;
	size_t	next;

	philo = (void *) data;
	table = philo->table;
	next = (philo->id + 1) % table->count;
	pthread_mutex_lock(&(philo->fork));
	pthread_mutex_lock(&(table->philos[next]->fork));
	print(philo, HAS_TAKEN_A_FORK);
	print(philo, HAS_TAKEN_A_FORK);
	philo_eat(philo);
	return (NULL);
}

void	*philo_eat(void *data)
{
	t_philo *philo;
	t_table	*table;
	size_t	next;

	philo = (void *) data;
	table = philo->table;
	next = (philo->id + 1) % table->count;
	print(philo, IS_EATING);
	usleep(410);
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock(&(table->philos[next]->fork));
	philo_sleep(philo);
	return (NULL);
}

void	*philo_sleep(void *data)
{
	t_philo *philo;
	t_table	*table;
	size_t	next;

	philo = (void *) data;
	table = philo->table;
	next = (philo->id + 1) % table->count;
	print(philo, IS_SLEEPING);
	usleep(200);
	philo_think(philo);
	return (NULL);
}

void	*philo_think(void *data)
{
	t_philo *philo;
	t_table	*table;
	size_t	next;

	philo = (void *) data;
	table = philo->table;
	next = (philo->id + 1) % table->count;
	print(philo, IS_THINKING);
	usleep(200);
	philo_take_fork(philo);
	return (NULL);
}

void	*philo_die(void *data)
{
	(void) data;
	return (NULL);
}
