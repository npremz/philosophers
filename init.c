/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:00:14 by npremont          #+#    #+#             */
/*   Updated: 2024/01/22 12:12:29 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(int ac, char **av, t_socrate *socrate)
{
	socrate->nb_philo = ft_atol(av[1]);
	socrate->time_to_die = ft_atol(av[2]);
	socrate->time_to_eat = ft_atol(av[3]);
	socrate->time_to_sleep = ft_atol(av[4]);
	if ((socrate->nb_philo < 0 || socrate->nb_philo > 2147483647)
		|| (socrate->time_to_die < 0 || socrate->time_to_die > 2147483647)
		|| (socrate->time_to_eat < 0 || socrate->time_to_eat > 2147483647)
		|| (socrate->time_to_sleep < 0 || socrate->time_to_sleep > 2147483647))
		ft_error("Error: invalid argument.\n", 1);
	if (ac == 6)
		socrate->eat_num = ft_atol([5]);
	if (socrate->time_to_sleep < 0 || socrate->time_to_sleep > 2147483647)
		ft_error("Error: invalid argument.\n", 1);
}
