/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:06:55 by npremont          #+#    #+#             */
/*   Updated: 2024/02/20 14:15:41 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_bool(t_mtx *mutex, bool *dest, bool value)
{
	if (ft_mutex_handle(mutex, LOCK))
		return (1);
	*dest = value;
	if (ft_mutex_handle(mutex, UNLOCK))
		return (1);
	return (0);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	ret;

	if (ft_mutex_handle(mutex, LOCK))
		return (-1);
	ret = *value;
	if (ft_mutex_handle(mutex, UNLOCK))
		return (-1);
	return (ret);
}

int	set_long(t_mtx *mutex, long *dest, long value)
{
	if (ft_mutex_handle(mutex, LOCK))
		return (1);
	*dest = value;
	if (ft_mutex_handle(mutex, UNLOCK))
		return (1);
	return (0);
}

long	get_long(t_mtx *mutex, long *value)
{
	long	ret;

	if (ft_mutex_handle(mutex, LOCK))
		return (-1);
	ret = *value;
	if (ft_mutex_handle(mutex, UNLOCK))
		return (-1);
	return (ret);
}

bool	simulation_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation));
}
