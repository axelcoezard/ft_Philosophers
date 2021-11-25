/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:28:10 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/25 19:05:05 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*parse(int ac, char **av)
{
	t_table	*table;

	if (!check_args(ac, av))
		return (NULL);
	table = malloc(sizeof(t_table));
	if (ac == MAX_ARGS + 1)
		table->min_to_eat = ft_atoi(av[MAX_ARGS]);
	else
		table->min_to_eat = -1;
	table->count = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->death = 0;
	table->philos = malloc(table->count * sizeof(t_philo));
	table->forks = malloc(table->count * sizeof(pthread_mutex_t));
	table->time = time_get_now();
	return (table);
}
