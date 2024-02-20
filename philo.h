/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:22:33 by npremont          #+#    #+#             */
/*   Updated: 2024/02/20 14:18:57 by npremont         ###   ########.fr       */
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
	t_fork	*forks;
	t_philo	*philos;
	long	mtx_inited;
}	t_table;

/* ENUMS */

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

/* PARSING FUNCTION
** -> Returns false if failed
*/

bool		ft_parse_input(t_table *table, char **av);

/* INIT FUNCTION 
** -> Returns false if failed
*/

bool		data_init(t_table *table);

/* THREADS FONCTION (including error gestion) 
** -> Returns true if an error occured
*/

bool		ft_thread_handle(pthread_t *thread, void *(*f)(void *),
				void *data, t_opcode opcode);
bool		ft_mutex_handle(t_mtx *mutex, t_opcode opcode);

/* SETTER AND GETTERS */

int			set_bool(t_mtx *mutex, bool *dest, bool value);
bool		get_bool(t_mtx *mutex, bool *value);
int			set_long(t_mtx *mutex, long *dest, long value);
long		get_long(t_mtx *mutex, long *value);
bool		simulation_finished(t_table *table);

/* UTILS FUNCTIONS */

size_t		ft_strlen(char *str);
void		*error(char *str);

/* FREE UTILS FUNCTIONS */

void		ft_free(void **ptr);
void		ft_destroy_mtx(t_table *table);

#endif
