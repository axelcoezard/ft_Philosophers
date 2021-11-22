/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:38:33 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/22 11:57:20 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table threads;

	(void) ac;
	(void) av;
	threads = threads_start(8);
	threads_wait(&threads);
	return (0);
}
