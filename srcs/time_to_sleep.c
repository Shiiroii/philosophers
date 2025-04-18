/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_to_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:24 by liulm             #+#    #+#             */
/*   Updated: 2025/04/18 18:21:14 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_to_sleep(t_philo *philo, int id)
{
	gettimeofday(&philo->tv, NULL);
	printf("%ld %d is sleeping\n", convert_time_milli(), id);
	usleep(philo->time_sleep * 1000);
	return (0);
}
