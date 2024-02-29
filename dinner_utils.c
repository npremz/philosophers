/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:47:09 by npremont          #+#    #+#             */
/*   Updated: 2024/02/29 10:48:46 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_all_philos(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nbr)
		if (ft_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
