/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:23 by liulm             #+#    #+#             */
/*   Updated: 2025/04/08 17:59:08 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_to_eat(t_philo *philo, int i)
{
	struct	timeval tv;

	pthread_mutex_lock(&philo->mutex_forks[i]);
	pthread_mutex_lock(&philo->mutex_forks[(i + 1) % philo->nb_philo]);
	pthread_mutex_lock(&philo->mutex_eat);
	philo->last_eat = gettimeofday(&tv, NULL);
	pthread_mutex_unlock(&philo->mutex_eat);
	pthread_mutex_lock(&philo->mutex_print);
	// ft_printf("%lld %d is eating\n", gettimeofday(&tv, NULL) - philo->start_time, i + 1);
	pthread_mutex_unlock(&philo->mutex_print);
	usleep(philo->time_eat * 1000);
	pthread_mutex_unlock(&philo->mutex_forks[i]);
	pthread_mutex_unlock(&philo->mutex_forks[(i + 1) % philo->nb_philo]);
	return (0);
}
