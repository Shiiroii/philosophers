/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:00:14 by lionelulm         #+#    #+#             */
/*   Updated: 2025/05/07 22:47:40 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	mutex_philo(pthread_mutex_t *mutex, t_mutex action)
{
	if (action == INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
		{
			printf("Init failed\n");
			return ;
		}
	}
	else if (action == LOCK)
	{
		if (pthread_mutex_lock(mutex) != 0)
		{
			printf("Lock failed\n");
			return ;
		}
	}
	else if (action == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex) != 0)
		{
			printf("Unlock failed\n");
			return ;
		}
	}
	else if (action == KILL)
	{
		if (pthread_mutex_destroy(mutex) != 0)
		{
			printf("Destroy failed\n");
			return ;
		}
	}
	return ;
}

void	pthread_philo(t_philo *philo, t_mutex mutex)
{
	if (mutex == CREATE)
		if (pthread_create(&philo->thread, NULL, philo_routine, philo) != 0)
		{
			printf("Creation failed\n");
			return ;
		}
	if (mutex == JOIN)
		if (pthread_join(philo->thread, NULL) != 0)
		{
			printf("Creation failed\n");
			return ;
		}
	return ;
}
