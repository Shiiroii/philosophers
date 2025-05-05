/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:06:31 by liulm             #+#    #+#             */
/*   Updated: 2025/04/28 14:28:58 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*free_philo(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->forks)
		free(philo->forks);
	if (philo->mutex_forks)
	{
		while (i < philo->nb_philo)
		{
			pthread_mutex_destroy(&philo->mutex_forks[i]);
			i++;
		}
		free(philo->mutex_forks);
	}
	pthread_mutex_destroy(&philo->mutex_eat);
	return (NULL);
}

int	checker(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (!ft_isdigit(argv[i][j]))
			return (1);
		i++;
	}
	if (ft_atoi(argv[1]) > 200)
	{
		write(1, "Error: Number of philosophers is too high\n", 43);
		return (1);
	}
	printf("CHECKER WORKED\n");
	return (0);
}

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
	printf("FORKS WORKED\n");
	return (forks);
}

void	mini_init(t_philo *philo, char **argv)
{
	philo->nb_philo = ft_atoi(argv[1]);
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->nb_of_eat = ft_atoi(argv[5]);
	else
		philo->nb_of_eat = -1;
}

int	initialize_philo(int argc, char **argv, t_philo **philo_ptr)
{
	t_philo	philo;
	int		i;

	ft_bzero(&philo, sizeof(t_philo));
	if (checker(argc, argv) == 1)
		return (1);
	mini_init(&philo, argv);
	philo.mutex_forks = malloc(sizeof(pthread_mutex_t) * philo.nb_philo);
	// philo.forks = initialize_forks(philo.nb_philo);
	if (!philo.mutex_forks)
	{
		free_philo(&philo);
		return (1);
	}
	i = 0;
	while (i < philo.nb_philo)
	{
		pthread_mutex_init(&philo.mutex_forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&philo.mutex_eat, NULL);
	printf("INIT WORKED\n");
	*philo_ptr = &philo;
	return (0);
}
