/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:00:14 by lionelulm         #+#    #+#             */
/*   Updated: 2025/05/08 15:28:15 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	mutex_init_philo(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		printf("Init failed\n");
		return ;
	}
}

void	mutex_lock_philo(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
	{
		printf("Lock failed\n");
		return ;
	}
}

void	mutex_unlock_philo(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
	{
		printf("Unlock failed\n");
		return ;
	}
}

void	pthread_create_philo(t_philo *philo)
{
	if (pthread_create(&philo->thread, NULL, philo_routine, philo) != 0)
	{
		printf("Creation failed\n");
		return ;
	}
}
