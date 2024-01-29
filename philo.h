/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:22:33 by npremont          #+#    #+#             */
/*   Updated: 2024/01/29 13:42:02 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "pthread.h"

typedef struct s_socrate
{
	unsigned int	nb_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	eat_num;
}	t_socrate;

/* INIT FUNCTIONS*/

void		ft_init(int ac, char **av, t_socrate *socrate);

/* UTILS FUNCTIONS */

long int	ft_atol(const char *nptr);
size_t		ft_strlen(char *str);
void		ft_error(char *str, int code);
