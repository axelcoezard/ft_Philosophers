/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:39:22 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/24 16:32:22 by acoezard         ###   ########.fr       */
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
typedef struct s_philo
{
	size_t			id;
	pthread_t		thread;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;

	int				eating;
	int				last_eating;
	int				sleeping;
	int				thinking;
	int				died;

	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	size_t			count;

	size_t			time_to_sleep;
	size_t			time_to_eat;
	size_t			time_to_die;
	size_t			min_to_eat;
	size_t			death;

	struct timeval	time;
	pthread_t		is_diying;
	pthread_mutex_t	is_printing;
}	t_table;

/* ********************** INPUT / OUTPUT ********************** */
void			print(t_philo *philo, char *message);

/* ************************* CHECKERS ************************* */

/* ************************* THREADS ************************** */
t_table			*threads_start(size_t count);
void			threads_wait(t_table *table);

/* ************************** PHILOS ************************** */
void			philo_init(t_philo *philo, t_table *table, int id);
void			philo_init_forks(t_philo *philo, t_table *table, int id);
void			*philo_routine(void *data);
void			philo_use_fork(t_philo *philo,
					int (*mutex_action)(), char *msg);
void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);
void			*philo_check_death(void *data);

/* *************************** TIME *************************** */
struct timeval	time_get_now(void);
size_t			time_get_millis(struct timeval time);
size_t			time_get_millis_now(void);
size_t			time_get_millis_from_start(t_table *table);

#endif
