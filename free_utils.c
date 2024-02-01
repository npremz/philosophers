/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:01:10 by npremont          #+#    #+#             */
/*   Updated: 2024/01/31 17:05:12 by npremont         ###   ########.fr       */
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
