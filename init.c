/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:22:13 by npremont          #+#    #+#             */
/*   Updated: 2024/01/31 17:37:35 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_get_forks(t_philo *philo, t_fork *forks, int philo_position)
{
	int	philo_nb;

	philo_nb = philo->table->philo_nbr;
	philo->first_fork = &forks[(philo_position + 1) % philo_nb];
	philo->second_fork = &forks[philo_position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_nb];
	}
}

static bool	ft_philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i;
		philo->full = false;
		philo->meals_counter = 0;
		philo->table = table;
		ft_get_forks(philo, table->forks, i);
	}
	return (true);
}

bool	data_init(t_table *table)
{
	int	i;

	table->end_simulation = false;
	table->mtx_inited = 0;
	table->philos = malloc(sizeof(t_philo) * table->philo_nbr);
	if (!(table->philos))
		return (false);
	table->forks = malloc(sizeof(t_fork) * table->philo_nbr);
	if (!(table->forks))
		return (ft_free((void **)&table->philos), false);
	i = -1;
	while (++i < table->philo_nbr)
	{
		if (ft_mutex_handle(&table->forks[i].fork, INIT))
			return (ft_destroy_mtx(table), ft_free((void **)&table->philos),
				ft_free((void **)&table->forks), false);
		++(table->mtx_inited);
		table->forks[i].fork_id = i;
	}
	if (!ft_philo_init(table))
		return (false);
	return (true);
}
