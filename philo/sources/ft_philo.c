/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:47:57 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/16 16:57:15 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO: Fix le type d'argument de (t_philo *) à (void *)
void	philo_take_fork(t_philo *philo)
{
	while (pthread_mutex_trylock(&(philo->next->fork)) == EBUSY)
		;
	pthread_mutex_lock(&(philo->fork));
	pthread_mutex_lock(&(philo->next->fork));
	print(philo, HAS_TAKEN_A_FORK);
	print(philo, HAS_TAKEN_A_FORK);
}

void	philo_eat(t_philo *philo)
{
	(void) philo;
}

void	philo_sleep(t_philo *philo)
{
	(void) philo;
}

void	philo_think(t_philo *philo)
{
	(void) philo;
}

void	philo_die(t_philo *philo)
{
	(void) philo;
}
