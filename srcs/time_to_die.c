/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:20 by liulm             #+#    #+#             */
/*   Updated: 2025/04/08 17:54:44 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_to_die(t_philo *philo, int i)
{
	struct	timeval tv;

	pthread_mutex_lock(&philo->mutex_print);
	ft_printf("%lld %d is dead\n", gettimeofday(&tv, NULL), i + 1);
	pthread_mutex_unlock(&philo->mutex_print);
	return (0);
}

void *philosopher_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	while (1)
	{
		printf("Philosopher %d is thinking\n", philo->id);
		usleep(philo->time_sleep * 1000);

		pthread_mutex_lock(&philo->mutex_forks[philo->id]);
		pthread_mutex_lock(&philo->mutex_forks[(philo->id + 1) % philo->nb_philo]);
		printf("Philosopher %d is eating\n", philo->id);
		usleep(philo->time_eat * 1000);
		pthread_mutex_unlock(&philo->mutex_forks[philo->id]);
		pthread_mutex_unlock(&philo->mutex_forks[(philo->id + 1) % philo->nb_philo]);

		printf("Philosopher %d is sleeping\n", philo->id);
		usleep(philo->time_sleep * 1000);
	}
	return (NULL);
}
