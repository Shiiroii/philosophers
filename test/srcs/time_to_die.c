/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:30:54 by lionelulm         #+#    #+#             */
/*   Updated: 2025/05/07 20:23:39 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philo_died(t_philo *philo)
{
	mutex_philo(&philo->info->end, LOCK);
	if (philo->info->finish)
	{
		mutex_philo(&philo->info->end, UNLOCK);
		return (1);
	}
	mutex_philo(&philo->info->end, UNLOCK);
	return (0);
}

int	dying_pause(t_philo *philo, unsigned long time)
{
	long int	start;

	start = convert_time_milli();
	while ((convert_time_milli() - start) < time)
	{
		if (philo_died(philo))
			return (1);
		if (time_to_die(philo))
			return (1);
		usleep (200);
	}
	return (0);
}

int	time_to_die(t_philo *philo)
{
	if ((convert_time_milli() - philo->last_eat) >= philo->info->time_to_die)
	{
		if (philo->info->finish == 0)
			philo_action(philo, DIED);
		mutex_philo(&philo->info->end, LOCK);
		philo->info->finish = 1;
		mutex_philo(&philo->info->end, UNLOCK);
		return (1);
	}
	return (0);
}
