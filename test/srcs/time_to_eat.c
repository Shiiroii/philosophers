/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:30:59 by lionelulm         #+#    #+#             */
/*   Updated: 2025/05/07 23:22:04 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	has_philo_eaten(t_philo *philo)
{
	if (philo->info->nb_of_rounds != -1 && (philo->meals == philo->info->nb_of_rounds))
	{
		philo->done = 1;
		return (1);
	}
	return (0);
}

int	philo_eating_odd(t_philo *philo)
{

	if (has_philo_eaten(philo))
		return (1);
	philo_action(philo, EATING);
	philo->last_eat = convert_time_milli();
	if (taking_a_break(philo, philo->info->time_to_eat))
		return (1);
	mutex_philo(&philo->next_philo->lock_fork, LOCK);
	mutex_philo(&philo->lock_fork, LOCK);
	philo->next_philo->fork = 1;
	philo->fork = 1;
	mutex_philo(&philo->lock_fork, UNLOCK);
	mutex_philo(&philo->next_philo->lock_fork, UNLOCK);
	philo->meals += 1;
	return (0);
}

int	philo_eating(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (has_philo_eaten(philo))
			return (1);
		philo_action(philo, EATING);
		philo->last_eat = convert_time_milli();
		if (taking_a_break(philo, philo->info->time_to_eat))
			return (1);
		mutex_philo(&philo->lock_fork, LOCK);
		mutex_philo(&philo->next_philo->lock_fork, LOCK);
		philo->fork = 1;
		philo->next_philo->fork = 1;
		mutex_philo(&philo->next_philo->lock_fork, UNLOCK);
		mutex_philo(&philo->lock_fork, UNLOCK);
		philo->meals += 1;
		return (0);
	}
	else
		return (philo_eating_odd(philo));
}

