/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:23 by liulm             #+#    #+#             */
/*   Updated: 2025/04/10 17:38:50 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_to_eat(t_philo *philo, int i)
{
	struct	timeval tv;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	if (philo->id % 2 == 0)
	{
		left_fork = &philo->mutex_forks[i];
		right_fork = &philo->mutex_forks[(i + 1) % philo->nb_philo];
	}
	else
	{
		left_fork = &philo->mutex_forks[(i + 1) % philo->nb_philo];
		right_fork = &philo->mutex_forks[i];
	}
	pthread_mutex_lock(left_fork);
	pthread_mutex_lock(right_fork);

	pthread_mutex_lock(&philo->mutex_eat);

	philo->last_eat = gettimeofday(&tv, NULL);

	pthread_mutex_unlock(&philo->mutex_eat);
	// pthread_mutex_lock(&philo->mutex_print);

	printf("Philosopher %d is eating\n", philo->id);

	pthread_mutex_unlock(&philo->mutex_print);

	usleep(philo->time_eat * 10);

	// pthread_mutex_unlock(&philo->mutex_forks[i]);
	// pthread_mutex_unlock(&philo->mutex_forks[(i + 1) % philo->nb_philo]);
	pthread_mutex_unlock(right_fork);
	pthread_mutex_unlock(left_fork);
	return (0);
}
