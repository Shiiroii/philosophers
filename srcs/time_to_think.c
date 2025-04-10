/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_think.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:26:21 by liulm             #+#    #+#             */
/*   Updated: 2025/04/10 15:41:09 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_to_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_print);
	printf("Philosopher %d is thinking\n", philo->id);
	pthread_mutex_unlock(&philo->mutex_print);
	return (0);
}
