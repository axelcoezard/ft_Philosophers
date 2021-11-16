/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:48:27 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/16 16:44:48 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	takefork(t_philo *philo)
{
	ft_log(philo, HAS_DIED);
	while (pthread_mutex_trylock(&(philo->next->fork)) == EBUSY)
		;
	pthread_mutex_lock(&(philo->fork));
	pthread_mutex_lock(&(philo->next->fork));
	ft_log(philo, HAS_TAKEN_A_FORK);
	ft_log(philo, HAS_TAKEN_A_FORK);
}

static void	*philosopher(void *p_data)
{
	t_philo	*philo;

	philo = (t_philo *) p_data;
	takefork(philo);
	return (NULL);
}

t_philo	**ft_threads_start(size_t count)
{
	t_philo	**philos;
	size_t	i;

	philos = (t_philo **) malloc((count + 1) * sizeof(t_philo *));
	if (philos == NULL)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		philos[i] = (t_philo *) malloc(sizeof(t_philo));
		philos[i]->id = i;
		pthread_create(&(philos[i]->thread), NULL, philosopher, philos[i]);
		pthread_mutex_init(&(philos[i]->fork), NULL);
	}
	philos[count] = NULL;
	return (philos);
}

void	ft_threads_wait(t_philo	**philos)
{
	size_t	i;

	i = 0;
	while (philos[i] != NULL)
	{
		pthread_join(philos[i]->thread, NULL);
		free(philos[i]);
		i++;
	}
	free(philos);
}
