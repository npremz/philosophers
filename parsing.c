/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:56:14 by npremont          #+#    #+#             */
/*   Updated: 2024/01/31 16:27:05 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline bool	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static bool	ft_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_is_space(str[i]) || (str[i] >= '0' && str[i] <= '9')
				|| str[i] == '-' || str[i] == '+'))
			return (false);
		++i;
	}
	return (true);
}

static char	*ft_check_input(char *str)
{
	int		i;
	char	*nbr;

	i = 0;
	if (!ft_is_valid(str))
		return (error("Error: Invalid input, numeric values only.\n"));
	while (ft_is_space(str[i]))
		++i;
	if (str[i] == '+')
		++i;
	else if (str[i] == '-')
		return (error("Error: This program takes only positive values.\n"));
	nbr = str + i;
	if (ft_strlen(nbr) > 10)
		return (error("Error: INT_MAX is the maximun input accepted.\n"));
	return (nbr);
}

static long	ft_atol(char *str)
{
	int		i;
	char	*str_nbr;
	long	nb;

	nb = 0;
	str_nbr = ft_check_input(str);
	if (!str_nbr)
		return (-2);
	i = 0;
	while (str_nbr[i])
		nb = (nb * 10) + (str_nbr[i++] - 48);
	if (nb > INT_MAX)
		return (error("Error: INT_MAX is the maximun input accepted.\n"), -2);
	return (nb);
}

bool	ft_parse_input(t_table *table, char **av)
{
	table->philo_nbr = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]) * 1e3;
	table->time_to_eat = ft_atol(av[3]) * 1e3;
	table->time_to_sleep = ft_atol(av[4]) * 1e3;
	if (av[5])
		table->nbr_limit_meals = ft_atol(av[5]);
	else
		table->nbr_limit_meals = -1;
	if (table->philo_nbr == -2 || table->time_to_die == -2
		|| table->time_to_eat == -2 || table->time_to_sleep == -2
		|| table->nbr_limit_meals == -2)
		return (false);
	return (true);
}
