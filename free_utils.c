/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:01:10 by npremont          #+#    #+#             */
/*   Updated: 2024/02/28 12:54:24 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	ft_destroy_mtx(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->mtx_inited)
	{
		ft_mutex_handle(&table->forks[i].fork, DESTROY);
	}
}

void	clean(t_table *table)
{
	t_philo *philo;
	int		i;

	i = -1;
	while (++i < table->philo_nbr)
	{
		philo = table->philos + i;
		ft_mutex_handle(&philo->philo_mutex, DESTROY);
	}
	ft_mutex_handle(&table->write_mutex, DESTROY);
	ft_mutex_handle(&table->table_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
}
