/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:20 by liulm             #+#    #+#             */
/*   Updated: 2025/04/15 15:41:40 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_to_die(t_philo *philo)
{
	struct timeval	tv;

	ft_printf("Philosopher %d is dead\n", philo->id);
	if(philo->last_eat + philo->time_die < gettimeofday(&tv, NULL))
	ft_printf("Philosopher %d is dead\n", philo->id);
	return (0);
}
