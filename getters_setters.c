/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:06:55 by npremont          #+#    #+#             */
/*   Updated: 2024/02/21 12:53:54 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(t_mtx *mutex, bool *dest, bool value)
{
	ft_mutex_handle(mutex, LOCK);
	*dest = value;
	ft_mutex_handle(mutex, UNLOCK);
	return (0);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	ret;

	ft_mutex_handle(mutex, LOCK);
	ret = *value;
	ft_mutex_handle(mutex, UNLOCK);
	return (ret);
}

void	set_long(t_mtx *mutex, long *dest, long value)
{
	ft_mutex_handle(mutex, LOCK);
	*dest = value;
	ft_mutex_handle(mutex, UNLOCK);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	ret;

	ft_mutex_handle(mutex, LOCK);
	ret = *value;
	ft_mutex_handle(mutex, UNLOCK);
	return (ret);
}

bool	simulation_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation));
}
