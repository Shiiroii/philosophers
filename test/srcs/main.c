/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:11:24 by lionelulm         #+#    #+#             */
/*   Updated: 2025/05/07 22:59:45 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void cleanup_philosophers(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_of_philo)
	{
		pthread_mutex_destroy(&philo[i].lock_fork);
		i++;
	}
	pthread_mutex_destroy(&info->end);
	pthread_mutex_destroy(&info->print);
	free(philo);
}


int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_info	info;
	int		i;

	philo = NULL;
	if (argc >= 5 && argc <= 6)
	{
		if (init_variables(argc, argv, &philo, &info) == 1)
		{
			write(1, "Error: Initialization failed\n", 28);
			return (1);
		}
		i = 0;
		while (i < info.nb_of_philo)
		{
			if (pthread_join(philo[i].thread, NULL) != 0)
				printf("Join failed for philosopher %d\n", i + 1);
			i++;
		}
		cleanup_philosophers(philo, &info);
	}
	else
	{
		write (1, "Usage : ./philosophers nb_phil time_die time_eat time_sleep [nb_of_eat]\n", 71);
		return (1);
	}
	return (0);
}
