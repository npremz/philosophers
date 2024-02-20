/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:28 by npremont          #+#    #+#             */
/*   Updated: 2024/02/20 14:20:49 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner_simulation(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	return (NULL);
}

int	dinner_start(t_table *table)
{
	int	i;

	i = -1;
	if (0 == table->nbr_limit_meals)
		return (EXIT_FAILURE);
	else if (1 == table->philo_nbr)
		;
	else
		while (++i < table->philo_nbr)
			ft_thread_handle(&table->philos[i].thread_id, dinner_simulation,
				&table->philos[i], CREATE);
	if (set_bool(&table->table_mutex, &table->all_threads_ready, true))
		return (EXIT_FAILURE);
}
