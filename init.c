/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:22:13 by npremont          #+#    #+#             */
/*   Updated: 2024/02/27 13:35:03 by npremont         ###   ########.fr       */
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
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->table = table;
		ft_mutex_handle(&philo->philo_mutex, INIT);
		ft_get_forks(philo, table->forks, i);
	}
	return (true);
}

bool	data_init(t_table *table)
{
	int	i;

	table->end_simulation = false;
	table->all_threads_ready = false;
	table->threads_running_nbr = 0;
	if (ft_mutex_handle(&table->table_mutex, INIT))
		return (false);
	if (ft_mutex_handle(&table->write_mutex, INIT))
		return (false);
	table->philos = malloc(sizeof(t_philo) * table->philo_nbr);
	if (!(table->philos))
		return (false);
	table->forks = malloc(sizeof(t_fork) * table->philo_nbr);
	if (!(table->forks))
		return (ft_free((void **)&table->philos), false);
	i = -1;
	while (++i < table->philo_nbr)
	{
		ft_mutex_handle(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	if (!ft_philo_init(table))
		return (false);
	return (true);
}
