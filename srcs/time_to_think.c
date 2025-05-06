/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   time_to_think.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: liulm <liulm@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/05 16:26:21 by liulm			 #+#	#+#			 */
/*   Updated: 2025/04/18 18:21:22 by liulm			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	time_to_think(t_philo *philo, int id)
{
	gettimeofday(&philo->tv, NULL);
	printf("%ld %d is thinking\n", convert_time_milli(), id);
	return (0);
}
