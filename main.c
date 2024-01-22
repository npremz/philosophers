/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:09:44 by npremont          #+#    #+#             */
/*   Updated: 2024/01/22 12:13:05 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_socrate	socrate;

	if (ac < 5 || av > 6)
		ft_error("Error: argument\n", 1);
	ft_init(ac, av, &socrate);
	return (0);
}