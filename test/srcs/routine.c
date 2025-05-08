/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:19:39 by lionelulm         #+#    #+#             */
/*   Updated: 2025/05/08 17:04:38 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_action(t_philo *philo, char *action)
{
	mutex_lock_philo(&philo->info->print);
	if (philo_died(philo))
	{
		mutex_unlock_philo(&philo->info->print);
		return ;
	}
	if (philo->info->finish == 0)
		printf("%ld %d %s\n", current_moment(philo), philo->id, action);
	mutex_unlock_philo(&philo->info->print);
}

int	thinking_pause(t_philo *philo, unsigned long time)
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

int	sleeping_thinking(t_philo *philo)
{
	if (has_philo_eaten(philo))
		return (1);
	philo_action(philo, SLEEPING);
	if (thinking_pause(philo, philo->info->time_to_sleep))
		return (1);
	philo_action(philo, THINKING);
	return (0);
}

static int	take_fork(t_philo *philo, pthread_mutex_t *lock_fork, int *fork)
{
	while (1)
	{
		if (time_to_die(philo) || philo_died(philo) || has_philo_eaten(philo))
			return (1);
		mutex_lock_philo(lock_fork);
		if (*fork)
		{
			*fork = 0;
			philo_action(philo, TAKINGFORK);
			mutex_unlock_philo(lock_fork);
			return (0);
		}
		mutex_unlock_philo(lock_fork);
	}
	return (1);
}

int	taking_a_break(t_philo *philo, unsigned long time)
{
	long int	start;

	start = convert_time_milli();
	while ((convert_time_milli() - start) < time)
	{
		if (philo_died(philo))
			return (1);
		usleep(500);
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo_action(philo, THINKING);
	if (philo->id % 2 == 0)
		taking_a_break(philo, 5);
	while (1)
	{
		if (take_fork(philo, &philo->lock_fork, &philo->fork))
			return (NULL);
		if (take_fork(philo, &philo->next_philo->lock_fork,
				&philo->next_philo->fork))
			return (NULL);
		if (philo_eating(philo))
			return (NULL);
		if (sleeping_thinking(philo))
			return (NULL);
	}
}
