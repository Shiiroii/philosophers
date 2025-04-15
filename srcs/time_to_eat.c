/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:23 by liulm             #+#    #+#             */
/*   Updated: 2025/04/15 15:25:07 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_to_eat(t_philo *philo, int i)
{
	struct	timeval tv;
	int		j = 1;

	// pthread_mutex_lock(philo->mutex_forks);
	if (philo->id % 2 == 0)
	{
		philo->left_fork = &philo[j].mutex_forks[i];
		philo->right_fork = &philo[j + 1].mutex_forks[(i + 1) % philo->nb_philo];
		ft_printf("1\n");
	}
	else
	{
		philo->left_fork = &philo[j].mutex_forks[(i + 1) % philo->nb_philo];
		philo->right_fork = &philo[j + 1].mutex_forks[i];
		ft_printf("2\n");
	}
	// pthread_mutex_unlock(philo->mutex_forks);
	// pthread_mutex_lock(philo->right_fork);
	// pthread_mutex_lock(philo->left_fork);

	// pthread_mutex_lock(&philo->mutex_eat);

	philo->last_eat = gettimeofday(&tv, NULL);

	// pthread_mutex_unlock(&philo->mutex_eat);

	printf("Philosopher %d is eating\n", philo->id);


	usleep(philo->time_eat * 10);

	// pthread_mutex_unlock(&philo->mutex_forks[i]);
	// pthread_mutex_unlock(&philo->mutex_forks[(i + 1) % philo->nb_philo]);
	// pthread_mutex_unlock(philo->right_fork);
	// pthread_mutex_unlock(philo->left_fork);
	return (0);
}
