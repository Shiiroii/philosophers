/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:11:24 by lionelulm         #+#    #+#             */
/*   Updated: 2025/05/08 15:43:11 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	cleanup_philosophers(t_philo *philo, t_info *info)
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
			return (1);
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
		printf("./philosophers nb_phil die_ms eat_ms sleep_ms [nb_meals]\n");
		return (1);
	}
	return (0);
}
