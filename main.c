/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:09:44 by npremont          #+#    #+#             */
/*   Updated: 2024/01/29 13:46:04 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_socrate	socrate;

	if (ac < 5 || ac > 6)
		ft_error("Error: argument\n", 1);
	ft_init(ac, av, &socrate);
	printf("nb philo: %d, time to die: %d, time to eat: %d, time to sleep: %d",
		socrate.nb_philo, socrate.time_to_die, socrate.time_to_eat, socrate.time_to_sleep);
	if (ac == 6)
		printf(", %d", socrate.eat_num);
	printf("\n");
	return (0);
}
