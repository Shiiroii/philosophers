/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:01:38 by liulm             #+#    #+#             */
/*   Updated: 2025/03/18 14:10:49 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (argc > 4 && argc < 7)
	{
		initialize_philo(argv[1]);
	}
	else
		write (1, "Usage : ./philosophers nb_phil time_die time_eat time_sleep [nb_of_eat]", 71);
	write(1, "\n", 1);
	return (0);
}
