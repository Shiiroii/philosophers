/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:38 by liulm             #+#    #+#             */
/*   Updated: 2025/04/28 14:33:04 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	int			id;
	t_philo		*philo;
	pthread_t	threads[ft_atoi(argv[1])];

	id = ft_atoi(argv[1]);
	philo = NULL;
	if (argc >= 5 && argc <= 6)
	{
		if (initialize_philo(argc, argv, &philo) == 1)
		{
			write(1, "Error: Initialization failed\n", 30);
			return (1);
		}
		while (id-- > 0)
			pthread_create(&threads[id], NULL, philosopher_routine(id, philo), (void *)&id);
		while (id++ < ft_atoi(argv[1]))
			pthread_join(threads[id], NULL);
	}
	else
		write (1, "Usage : ./philosophers nb_phil time_die time_eat time_sleep [nb_of_eat]", 71);
	write(1, "\n", 1);
	return (0);
}
