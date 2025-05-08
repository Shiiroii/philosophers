/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:25:01 by lionelulm         #+#    #+#             */
/*   Updated: 2025/05/08 15:57:00 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return(1);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && (nptr[i] <= 13)))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

unsigned long	convert_time_milli(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

unsigned long	current_moment(t_philo *philo)
{
	unsigned long	start;
	struct timeval	tv;

	start = philo->info->start;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - start);
}

// void	philo_finish(t_philo **philo, t_info *info)
// {
// 	int i;

// 	i = 0;
// 	if (*philo == NULL)
// 		return ;
// 	while (i < info->nb_of_philo - 1)
// 	{
// 		mutex_philo(&(*philo)[i].lock_fork, KILL);
// 		i++;
// 	}
// 	mutex_philo(&(*info).print, KILL);
// 	mutex_philo(&(*info).end, KILL);
// 	free(*philo);
// }
