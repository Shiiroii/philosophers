/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   routine.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: liulm <liulm@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/10 15:39:25 by liulm			 #+#	#+#			 */
/*   Updated: 2025/05/06 16:27:11 by liulm			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	convert_time_milli(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void *philosopher_routine(int id, t_philo *philo)
{
	struct timeval tv;

	while (1)
	{

		time_to_eat(philo, philo->nb_philo, id);
		usleep(100);
		time_to_think(philo, id);
		usleep(100);
		if (philo->last_eat + philo->time_die < gettimeofday(&tv, NULL))
			time_to_die(philo, id);
		else
			time_to_sleep(philo, id);
	}
	return (NULL);
}

