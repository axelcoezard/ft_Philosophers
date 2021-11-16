/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:39:22 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/16 16:54:17 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ************************* INCLUDES ************************* */
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>

/* ************************* DEFINES ************************** */
# define HAS_TAKEN_A_FORK	"has taken a fork"
# define IS_EATING			"is eating"
# define IS_SLEEPING		"is sleeping"
# define IS_THINKING		"is thinking"
# define HAS_DIED			"died"

/* ************************ STRUCTURES ************************ */
struct s_philo
{
	size_t			id;
	pthread_t		thread;
	pthread_mutex_t	fork;

	struct s_philo	*next;
};
typedef struct s_philo	t_philo;

/* ********************** INPUT / OUTPUT ********************** */
void		print(t_philo *philo, char *message);

/* ************************* THREADS ************************** */
t_philo		**threads_start(size_t count);
void		threads_wait(t_philo	**philos);

/* ************************** PHILOS ************************** */
void		philo_take_fork(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_die(t_philo *philo);

#endif