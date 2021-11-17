/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:38:29 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/17 22:08:02 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, char *message)
{
	struct timeval	time;
	size_t			millis;

	gettimeofday(&time, NULL);
	millis = /*time.tv_sec * 1000 + */time.tv_usec/* / 1000*/;
	printf("%zu %zu %s\n", millis, philo->id + 1, message);
}
