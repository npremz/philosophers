/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:09:44 by npremont          #+#    #+#             */
/*   Updated: 2024/02/27 10:55:38 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (5 == ac || 6 == ac)
	{
		if (!ft_parse_input(&table, av))
			return (EXIT_FAILURE);
		if (!data_init(&table))
			return (error("Error: data init failed.\n"), EXIT_FAILURE);
		if (dinner_start(&table))
			return (error("Error: dinner failed\n"), EXIT_FAILURE);
	}
	else
		return (error("Wrong input! Correct: ./philo 5 800 200 200 [5]\n"), 1);
}
