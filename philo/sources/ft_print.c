/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:38:29 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/24 16:17:00 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief	La fonction print permet d'ecrire dans le stdin
 * 			un message relatif a une action d'un philosophe.
 *
 * @param	philo	Le philosophe qui realise l'action.
 * @param	table	Le message de l'action.
 */
void	print(t_philo *philo, char *message)
{
	if (message != NULL)
	{
		pthread_mutex_lock(&philo->table->is_printing);
		printf("%zu %zu %s\n", \
			time_get_millis_from_start(philo->table), \
			philo->id, \
			message \
		);
		pthread_mutex_unlock(&philo->table->is_printing);
	}
}
