/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:39:25 by liulm             #+#    #+#             */
/*   Updated: 2025/04/18 18:20:18 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	convert_time_milli(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void *philosopher_routine(int id, void *arg)
{
	t_philo *philo = (t_philo *)arg;
	struct timeval tv;
	// int i = 1;

	while (1)
	{
		// pthread_mutex_lock(&philo->mutex_forks[philo->id]);
		// pthread_mutex_lock(&philo->mutex_forks[(philo->id + 1) % philo->nb_philo]);
		// ft_printf("Philosopher %d is eating\n", philo->id);
		time_to_eat(philo, philo->nb_philo, id);
		usleep(100);
		// pthread_mutex_unlock(&philo->mutex_forks[philo->id]);
		// pthread_mutex_unlock(&philo->mutex_forks[(philo->id + 1) % philo->nb_philo]);

		// ft_printf("Philosopher %d is thinking\n", philo->id);
		time_to_think(philo, id);
		usleep(100);
		// ft_printf("Philosopher %d is sleeping\n", philo->id);
		// if (philo has eaten);
		if (philo->last_eat + philo->time_die < gettimeofday(&tv, NULL))
			time_to_die(philo, id);
		else
			time_to_sleep(philo, id);
	}
	return (NULL);
}

