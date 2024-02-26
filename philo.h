/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:22:33 by npremont          #+#    #+#             */
/*   Updated: 2024/02/26 18:39:52 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>
# include <errno.h>

# define DEBUG_MODE 0

/* SHORTCUT */

typedef pthread_mutex_t	t_mtx;
typedef struct s_table	t_table;

/* STRUCTS */

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_mtx		philo_mutex;
	t_table		*table;
}	t_philo;

typedef struct s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meals;
	long	start_simulation;
	bool	end_simulation;
	bool	all_threads_ready;
	t_mtx	table_mutex;
	t_mtx	write_mutex;
	t_fork	*forks;
	t_philo	*philos;
	long	mtx_inited;
}	t_table;

/* ENUMS */

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_philo_status;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND
}	t_time_code;

/* PARSING FUNCTION
** -> Returns false if failed
*/

bool		ft_parse_input(t_table *table, char **av);

/* INIT FUNCTION 
** -> Returns false if failed
*/

bool		data_init(t_table *table);

/* THREADS FONCTIONS (including error gestion) 
** -> Returns true if an error occured
*/

bool		ft_thread_handle(pthread_t *thread, void *(*f)(void *),
				void *data, t_opcode opcode);
bool		ft_mutex_handle(t_mtx *mutex, t_opcode opcode);

/* WRITING FUNCTIONS */

void		write_status(t_philo_status status, t_philo *philo, bool debug);

/* SYNC UTILS */

void		wait_all_threads(t_table *table);

/* SETTER AND GETTERS */

void		set_bool(t_mtx *mutex, bool *dest, bool value);
bool		get_bool(t_mtx *mutex, bool *value);
void		set_long(t_mtx *mutex, long *dest, long value);
long		get_long(t_mtx *mutex, long *value);
bool		simulation_finished(t_table *table);

/* UTILS FUNCTIONS */

size_t		ft_strlen(char *str);
void		*error(char *str);
long		gettime(t_time_code time_code);
void		precise_usleep(long usec, t_table *table);

/* FREE UTILS FUNCTIONS */

void		ft_free(void **ptr);
void		ft_destroy_mtx(t_table *table);

#endif
