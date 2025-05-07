/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:14:52 by lionelulm         #+#    #+#             */
/*   Updated: 2025/05/07 22:59:21 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	put_into_life(t_philo *philo, t_info *info, int nb)
{
	(philo)[nb].id = nb + 1;
	(philo)[nb].info = info;
	(philo)[nb].fork = 1;
	(philo)[nb].meals = 0;
	(philo)[nb].last_eat = info->start;
	(philo)[nb].done = 0;
	if (nb == info->nb_of_philo - 1)
		(philo)[nb].next_philo = &philo[0];
	else
		(philo)[nb].next_philo = &philo[nb + 1];
}

void	init_philo(t_philo **philo, t_info *info)
{
	int	i;

	i = 0;
	mutex_philo(&info->end, INIT);
	mutex_philo(&info->print, INIT);
	info->start = convert_time_milli();
	while (i < info->nb_of_philo)
	{
		put_into_life(*philo, info, i);
		if (pthread_mutex_init(&((*philo)[i].lock_fork), NULL) != 0)
		{
			printf("Mutex initialization failed\n");
			return;
		}
		i++;
	}
	i = 0;
	while (i < info->nb_of_philo)
	{
		pthread_philo(&(*philo)[i], CREATE);
		i++;
	}
}

int	checker(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 1)
	{
		printf("Invalid number of philosophers\n");
		return (1);
	}
	while (argc-- > 1)
	{
		if (is_number(argv[argc]) == 0)
		{
			printf("Variables are not all numbers\n");
			return (1);
		}
		if (ft_atoi(argv[argc]) <= 0)
		{
			printf("Numbers cant be negative\n");
			return (1);
		}
		if (ft_atoi(argv[argc]) > 2147483647)
		{
			printf("Numbers are too high\n");
			return (1);
		}
	}
	return (0);
}

void	mini_init(t_info *info, char **argv)
{
	info->nb_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->finish = 0;
}
int	init_variables(int argc, char **argv, t_philo **philo, t_info *info)
{
	if (checker(argc, argv) == 1)
		return (1);
	if (argc == 6)
		info->nb_of_rounds = ft_atoi(argv[5]);
	else
		info->nb_of_rounds = -1;
	if (ft_atoi(argv[1]) > 300)
	{
		printf("Too many philosophers");
		return (1);
	}
	mini_init(info, argv);
	*philo = malloc(sizeof(t_philo) * info->nb_of_philo);
	if (*philo == NULL)
		return (1);
	init_philo(philo, info);
	// philo_finish(philo, info);
	return (0);
}
