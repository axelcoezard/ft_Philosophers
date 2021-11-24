/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:38:56 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/24 16:42:07 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_use_fork(t_philo *philo,
			int (*mutex_action)(), char *message)
{
	mutex_action(philo->lfork);
	print(philo, message);
	mutex_action(philo->rfork);
	print(philo, message);
}

void	philo_eat(t_philo *philo)
{
	philo_use_fork(philo, pthread_mutex_lock, HAS_TAKEN_A_FORK);
	philo->last_eating = time_get_millis_now();
	philo->eating = 1;
	print(philo, IS_EATING);
	usleep(philo->table->time_to_eat * 1000);
	philo_use_fork(philo, pthread_mutex_unlock, NULL);
	philo->eating = 0;
}

void	philo_sleep(t_philo *philo)
{
	philo->sleeping = 1;
	print(philo, IS_SLEEPING);
	usleep(philo->table->time_to_sleep * 1000);
	philo->sleeping = 0;
}

void	philo_think(t_philo *philo)
{
	if (philo->sleeping || philo->eating)
		return ;
	print(philo, IS_THINKING);
}
