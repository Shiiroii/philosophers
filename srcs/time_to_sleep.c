/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:24 by liulm             #+#    #+#             */
/*   Updated: 2025/04/08 17:55:48 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_to_sleep(t_philo *philo, int i)
{
	struct	timeval tv;

	pthread_mutex_lock(&philo->mutex_print);
	ft_printf("%lld %d is sleeping\n", gettimeofday(&tv, NULL) - philo->start_time, i + 1);
	pthread_mutex_unlock(&philo->mutex_print);
	usleep(philo->time_sleep * 1000);
	return (0);
}
