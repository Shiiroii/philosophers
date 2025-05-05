/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:23 by liulm             #+#    #+#             */
/*   Updated: 2025/04/28 15:10:13 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_to_eat(t_philo *philo, int i, int id)
{
	// pthread_mutex_lock(philo->mutex_forks);
	printf("number of philosophers = %d\n", philo->nb_philo);
	if (id % 2 == 0)
	{
		philo->left_fork = &philo->mutex_forks[i];
		philo->right_fork = &philo->mutex_forks[(i + 1) % philo->nb_philo];
		printf("1\n");
	}
	else if (id != 0)
	{
		philo->left_fork = &philo->mutex_forks[(i + 1) % philo->nb_philo];
		philo->right_fork = &philo->mutex_forks[i];
		printf("2\n");
	}
	printf("Philosopher %d: Left fork = %p, Right fork = %p\n", id, philo->left_fork, philo->right_fork);
	pthread_mutex_lock(philo->right_fork);
	// pthread_mutex_lock(philo->left_fork);

	pthread_mutex_lock(&philo->mutex_eat);

	philo->last_eat = convert_time_milli();

	pthread_mutex_unlock(&philo->mutex_eat);

	printf("%ld %d is eating\n", convert_time_milli(), id);


	usleep(philo->time_eat * 10);

	pthread_mutex_unlock(philo->right_fork);
	// pthread_mutex_unlock(philo->left_fork);
	return (0);
}
