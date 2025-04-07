/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:24 by liulm             #+#    #+#             */
/*   Updated: 2025/04/05 16:46:16 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	time_to_sleep(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->mutex_print);
	ft_printf("%lld %d is sleeping\n", get_time() - philo->start_time, i + 1);
	pthread_mutex_unlock(&philo->mutex_print);
	usleep(philo->time_sleep * 1000);
	return (0);
}
