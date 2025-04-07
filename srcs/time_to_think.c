/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_think.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:26:21 by liulm             #+#    #+#             */
/*   Updated: 2025/04/05 16:26:33 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	time_to_think(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->mutex_print);
	ft_printf("%lld %d is thinking\n", get_time() - philo->start_time, i + 1);
	pthread_mutex_unlock(&philo->mutex_print);
	return (0);
}
