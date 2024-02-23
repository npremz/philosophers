/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:15:53 by npremont          #+#    #+#             */
/*   Updated: 2024/02/21 13:41:35 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	ft_handle_mtx_err(int status, t_opcode opcode)
{
	if (0 == status)
		return (false);
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		return (error("The value specified by mutex is invalid\n"), true);
	else if (EINVAL == status && INIT == opcode)
		return (error("The value specified by attr is invalid.\n"), true);
	else if (EDEADLK == status)
		return (error("A deadlock would occur if the thread "
				"blocked waiting for mutex.\n"), true);
	else if (EPERM == status)
		return (error("The current thread does not hold "
				"a lock on mutex.\n"), true);
	else if (ENOMEM == status)
		return (error("The process cannot allocate enough memory"
				" to create another mutex.\n"), true);
	else if (EBUSY == status)
		return (error("Mutex is locked\n"), true);
	return (true);
}

static bool	ft_hdl_trd_err(int status, t_opcode opcode)
{
	if (0 == status)
		return (false);
	if (EAGAIN == status)
		return (error("No resources to create another thread\n"), true);
	else if (EPERM == status)
		return (error("The caller don't have appropriate permission\n"), true);
	else if (EINVAL == status && CREATE == opcode)
		return (error("The value specified by attr is invalid.\n"), true);
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		return (error("The value specified by thread is not joinable\n"), true);
	else if (ESRCH == status)
		return (error("No thread could be found corresponding to that"
				"specified by the given thread ID, thread.\n"), true);
	else if (EDEADLK == status)
		return (error("A deadlock was detected or the value of"
				"thread specifies the calling thread.\n"), true);
	return (true);
}

bool	ft_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		return (ft_handle_mtx_err(pthread_mutex_lock(mutex), opcode));
	else if (UNLOCK == opcode)
		return (ft_handle_mtx_err(pthread_mutex_unlock(mutex), opcode));
	else if (INIT == opcode)
		return (ft_handle_mtx_err(pthread_mutex_init(mutex, NULL), opcode));
	else if (DESTROY == opcode)
		return (ft_handle_mtx_err(pthread_mutex_destroy(mutex), opcode));
	else
		return (error("Wrong opcode for ft_mutex_handle\n"), true);
}

bool	ft_thread_handle(pthread_t *thread, void *(*f)(void *),
			void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		return (ft_hdl_trd_err(pthread_create(thread, NULL, f, data), opcode));
	else if (JOIN == opcode)
		return (ft_hdl_trd_err(pthread_join(*thread, NULL), opcode));
	else if (DETACH == opcode)
		return (ft_hdl_trd_err(pthread_detach(*thread), opcode));
	else
		return (error("Wrong opcode for ft_thread_handle\n"), true);
}
