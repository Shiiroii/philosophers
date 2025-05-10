/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:12:55 by lionelulm         #+#    #+#             */
/*   Updated: 2025/05/10 18:20:30 by liulm            ###   ########.fr       */
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

# define THINKING "is thinking"
# define TAKINGFORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define DIED "has died"

typedef struct s_info
{
	int				nb_of_philo;
	int				nb_of_rounds;
	int				finish;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	time_to_die;
	unsigned long	start;
	pthread_mutex_t	end;
	pthread_mutex_t	print;
}		t_info;

typedef struct s_philo	t_philo;

typedef struct s_philo
{
	int				id;
	int				meals;
	int				done;
	int				fork;
	t_info			*info;
	pthread_t		thread;
	unsigned long	last_eat;
	pthread_mutex_t	lock_fork;
	t_philo			*next_philo;
}		t_philo;

// int				ft_atoi(const char *nptr);
int				is_number(char *str);
int				time_to_die(t_philo *philo);
int				taking_a_break(t_philo *philo, unsigned long time);
int				philo_eating(t_philo *philo);
int				has_philo_eaten(t_philo *philo);
int				philo_died(t_philo *philo);
int				sleeping_thinking(t_philo *philo);
int				thinking_pause(t_philo *philo, unsigned long time);
long			ft_atol(const char *nptr);
void			pthread_create_philo(t_philo *philo);
void			mutex_lock_philo(pthread_mutex_t *mutex);
void			mutex_unlock_philo(pthread_mutex_t *mutex);
void			mutex_init_philo(pthread_mutex_t *mutex);
void			philo_action(t_philo *philo, char *action);
void			*philo_routine(void *arg);
unsigned long	convert_time_milli(void);
unsigned long	current_moment(t_philo *philo);
int				init_variables(int argc, char **argv,
					t_philo **philo, t_info *info);

#endif
