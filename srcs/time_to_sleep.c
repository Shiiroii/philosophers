/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:24 by liulm             #+#    #+#             */
/*   Updated: 2025/04/10 15:41:06 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_to_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_print);
	printf("Philosopher %d is sleeping\n", philo->id);
	pthread_mutex_unlock(&philo->mutex_print);
	usleep(philo->time_sleep * 1000);
	return (0);
}
