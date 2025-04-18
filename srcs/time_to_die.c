/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:20 by liulm             #+#    #+#             */
/*   Updated: 2025/04/18 18:21:05 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_to_die(t_philo *philo, int id)
{
	if(philo->last_eat + philo->time_die < gettimeofday(&philo->tv, NULL))
	ft_printf("%ld %d has died\n", convert_time_milli(), id);
	return (0);
}
