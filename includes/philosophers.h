/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:04:27 by liulm             #+#    #+#             */
/*   Updated: 2025/04/28 14:33:11 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct	s_philo
{
	int					nb_philo;
	int					time_die;
	int					time_eat;
	int					last_eat;
	int					time_sleep;
	int					nb_of_eat;
	int					*forks;
	pthread_t			thread;
	pthread_mutex_t		*mutex_forks;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		mutex_eat;
	pthread_mutex_t		start_time;
	struct timeval		tv;
}		t_philo;

int		initialize_philo(int argc, char **argv, t_philo **philo_ptr);
void	*philosopher_routine(int id, t_philo *philo);
int		time_to_think(t_philo *philo, int id);
int		time_to_die(t_philo *philo, int id);
int		time_to_eat(t_philo *philo, int i, int id);
int		time_to_sleep(t_philo *philo, int id);
long	convert_time_milli(void);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);

#endif
