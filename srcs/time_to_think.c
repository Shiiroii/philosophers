/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_think.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:26:21 by liulm             #+#    #+#             */
/*   Updated: 2025/04/08 17:55:51 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_to_think(t_philo *philo, int i)
{
	struct	timeval tv;

	pthread_mutex_lock(&philo->mutex_print);
	ft_printf("%lld %d is thinking\n", gettimeofday(&tv, NULL) - philo->start_time, i + 1);
	pthread_mutex_unlock(&philo->mutex_print);
	return (0);
}
