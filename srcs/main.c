/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: liulm <liulm@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/18 14:01:38 by liulm			 #+#	#+#			 */
/*   Updated: 2025/05/06 16:29:11 by liulm			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/philosophers.h"

// int	main(int argc, char **argv)
// {
// 	t_philo		*philo;
// 	pthread_t	*threads;
// 	int			i;

// 	if (argc >= 5 && argc <= 6)
// 	{
// 		if (initialize_philo(argc, argv, &philo) == 1)
// 		{
// 			write(1, "Error: Initialization failed\n", 30);
// 			return (1);
// 		}
// 		while (id-- > 0)
// 			pthread_create(&threads[id], NULL, philosopher_routine(id, philo), (void *)&id);
// 		while (id++ < ft_atoi(argv[1]))
// 			pthread_join(threads[id], NULL);
// 	}
// 	else
// 		write (1, "Usage : ./philosophers nb_phil time_die time_eat time_sleep [nb_of_eat]", 71);
// 	write(1, "\n", 1);
// 	return (0);
// }

int main(int argc, char **argv)
{
	t_philo *philo;
	pthread_t *threads;
	int i;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philosophers nb_philo time_die time_eat time_sleep [nb_of_eat]\n");
		return (1);
	}

	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	threads = malloc(sizeof(pthread_t) * ft_atoi(argv[1]));
	if (!philo || !threads)
		return (1);

	initialize_philo(argc, argv, &philo);

	i = 0;
	while (i < philo[0].nb_philo)
	{
		pthread_create(&threads[i], NULL, philosopher_routine(i, philo), &philo[i]);
		i++;
	}

	i = 0;
	while (i < philo[0].nb_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}

	free(threads);
	free(philo);
	return (0);
}
