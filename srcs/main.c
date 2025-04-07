/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:38 by liulm             #+#    #+#             */
/*   Updated: 2025/04/07 17:22:58 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	if (argc >= 5 && argc <= 6)
	{
		if (initialize_philo(argc, &*argv) == 1)
		{
			write(1, "Error: Initialization failed\n", 30);
			return (1);
		}
		philosopher_routine(argv);
	}
	else
		write (1, "Usage : ./philosophers nb_phil time_die time_eat time_sleep [nb_of_eat]", 71);
	write(1, "\n", 1);
	return (0);
}
