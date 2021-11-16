/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:48:27 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/16 16:55:47 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**threads_start(size_t count)
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
		// TODO: #1 Muter la liste en liste chainee cyclique
		pthread_create(&(philos[i]->thread), NULL, philo_take_fork, philos[i]);
		pthread_mutex_init(&(philos[i]->fork), NULL);
	}
	philos[count] = NULL;
	return (philos);
}

void	threads_wait(t_philo	**philos)
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
