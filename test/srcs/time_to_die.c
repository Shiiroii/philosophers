/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:30:54 by lionelulm         #+#    #+#             */
/*   Updated: 2025/05/08 15:34:23 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	philo_died(t_philo *philo)
{
	mutex_lock_philo(&philo->info->end);
	if (philo->info->finish)
	{
		mutex_unlock_philo(&philo->info->end);
		return (1);
	}
	mutex_unlock_philo(&philo->info->end);
	return (0);
}

int	time_to_die(t_philo *philo)
{
	if ((convert_time_milli() - philo->last_eat) >= philo->info->time_to_die)
	{
		if (philo->info->finish == 0)
			philo_action(philo, DIED);
		mutex_lock_philo(&philo->info->end);
		philo->info->finish = 1;
		mutex_unlock_philo(&philo->info->end);
		return (1);
	}
	return (0);
}
