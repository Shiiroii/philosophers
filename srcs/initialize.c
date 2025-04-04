/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:06:31 by liulm             #+#    #+#             */
/*   Updated: 2025/04/04 16:26:50 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	*initialize_forks(int nb_philo)
{
	int	*forks;
	int	i;

	forks = malloc(sizeof(int) * nb_philo);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nb_philo)
	{
		forks[i] = 0;
		i++;
	}
	return (forks);
}

int	initialize_philo(char **argv)
{
	t_philo	philo;
	int		i;

	philo.nb_philo = ft_atoi(argv[1]);
	philo.time_die = ft_atoi(argv[2]);
	philo.time_eat = ft_atoi(argv[3]);
	philo.time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo.nb_of_eat = ft_atoi(argv[5]);
	else
		philo.nb_of_eat = -1;
	philo.forks = initialize_forks(philo.nb_philo);
	if (!philo.forks)
		return (1);
	i = 0;
	while (i < philo.nb_philo)
	{
		pthread_mutex_init(&philo.mutex_forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&philo.mutex_print, NULL);
	pthread_mutex_init(&philo.mutex_eat, NULL);
	return (0);
}
