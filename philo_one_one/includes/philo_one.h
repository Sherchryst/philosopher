/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frtalleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:20:40 by frtalleu          #+#    #+#             */
/*   Updated: 2021/04/14 15:33:00 by frtalleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHILO_ONE_H
# define _PHILO_ONE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# define DEAD	0
# define THINK	1
# define EAT	2
# define SLEEP	3
# define FORK	4

typedef struct		s_fork
{
	pthread_mutex_t	*fork;
	int				free_fork;
}					t_fork;

typedef struct		s_philo_info
{
	unsigned int	nb_philo;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	nb_eat;
	int				is_dead;
	int				limit_eat;
	int				begin;
	pthread_mutex_t	*print;
	t_fork			*forks;
	int				print_access;
	struct timeval	start;
}					t_philo_info;

typedef struct		s_philo
{
	t_philo_info	*phil_info;
	int				state;
	int				id;
	int				eat;
	unsigned int	last_eat;
	t_fork			*fork_r;
	t_fork			*fork_l;
}					t_philo;

unsigned int		time_lapse(struct timeval time);
void				ft_usleep(unsigned int time_wait);
void				take_fork(t_philo *philo);
t_philo				*free_fork(t_philo *philo);
void				*make_philo(void *data);
t_philo				*routine(t_philo *philo, t_philo_info *info);
int					ft_atois(char *str, unsigned int *j);
t_philo_info		*init_philo_struct(void);
void				ft_free(t_philo_info *info);
t_fork				*create_mutex(t_philo_info *info);
t_philo				create_philos_struct(t_philo_info *infos,
					int i, t_philo philo);
#endif
