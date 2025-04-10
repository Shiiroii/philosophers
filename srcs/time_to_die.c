/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:20 by liulm             #+#    #+#             */
/*   Updated: 2025/04/10 15:40:25 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_to_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_print);
	ft_printf("Philosopher %d is dead\n", philo->id);
	pthread_mutex_unlock(&philo->mutex_print);
	return (0);
}
