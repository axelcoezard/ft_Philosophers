/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:38:29 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/22 11:52:19 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, char *message)
{
	size_t			millis;

	millis = time_get_millis_from_start(philo->table);
	printf("%zu %zu %s\n", millis, philo->id + 1, message);
}
