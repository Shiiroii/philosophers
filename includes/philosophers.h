/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:04:27 by liulm             #+#    #+#             */
/*   Updated: 2025/04/14 14:02:59 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../utils/libft/libft.h"
# include "../utils/ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philo
{
	int				id;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				last_eat;
	int				time_sleep;
	int				nb_of_eat;
	int				*forks;
	pthread_t		thread;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	start_time;
}	t_philo;

int	initialize_philo(int argc, char **argv);
void *philosopher_routine(void *arg);
int	time_to_think(t_philo *philo);
int	time_to_die(t_philo *philo);
int	time_to_eat(t_philo *philo, int i);
int	time_to_sleep(t_philo *philo);

#endif
