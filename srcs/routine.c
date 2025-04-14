/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:39:25 by liulm             #+#    #+#             */
/*   Updated: 2025/04/14 14:21:29 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void *philosopher_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	// int i = 1;

	while (1)
	{

		// pthread_mutex_lock(&philo->mutex_forks[philo->id]);
		// pthread_mutex_lock(&philo->mutex_forks[(philo->id + 1) % philo->nb_philo]);
		// ft_printf("Philosopher %d is eating\n", philo->id);
		time_to_eat(philo, philo->nb_philo);
		usleep(philo->time_eat * 10);
		// pthread_mutex_unlock(&philo->mutex_forks[philo->id]);
		// pthread_mutex_unlock(&philo->mutex_forks[(philo->id + 1) % philo->nb_philo]);

		// ft_printf("Philosopher %d is thinking\n", philo->id);
		time_to_think(philo);
		usleep(philo->time_sleep * 10);
		// ft_printf("Philosopher %d is sleeping\n", philo->id);
		if (philo has eaten);
		usleep(philo->time_sleep * 10);
		else
			time_to_die(philo);
	}
	return (NULL);
}
