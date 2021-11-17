/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:39:22 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/17 21:39:07 by acoezard         ###   ########.fr       */
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

	struct s_table	*table;
};
typedef struct s_philo	t_philo;

struct s_table
{
	t_philo	**philos;
	size_t	count;
};
typedef struct s_table	t_table;

/* ********************** INPUT / OUTPUT ********************** */
void		print(t_philo *philo, char *message);

/* ************************* THREADS ************************** */
t_table		threads_start(size_t count);
int			threads_count(t_table *table);
void		threads_wait(t_table *table);

/* ************************** PHILOS ************************** */
void		*philo_take_fork(void *data);
void		*philo_eat(void *data);
void		*philo_sleep(void *data);
void		*philo_think(void *data);
void		*philo_die(void *data);

#endif
