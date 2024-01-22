/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:21:07 by npremont          #+#    #+#             */
/*   Updated: 2024/01/22 12:11:18 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_atol(const char *nptr)
{
	int				i;
	int				sign;
	long long int	nb;
	long long int	last;

	i = 0;
	sign = 1;
	nb = 0;
	last = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign *= -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i++] - 48);
		if (last > nb)
			return (2147483648);
		last = nb;
	}
	return (nb * sign);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	while (str[i])
		++i;
	return (i);
}

void	ft_error(char *str, int code)
{
	write(2, str, ft_strlen(str));
	exit(code);
}
