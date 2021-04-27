/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:54:28 by sgah              #+#    #+#             */
/*   Updated: 2021/04/27 23:24:54 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# define DEAD	0
# define THINK	1
# define EAT	2
# define SLEEP	3
# define FORK	4

# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>

# include "typedef.h"

/*
***PHILOSOPHER
*/
void			launch_philosopher(t_philosopher *info);
void			philosopher(t_philo *philo);

/*
***AFF
*/
void			display_philo(t_philo *philo, int state);

/*
***TOOLS_TIME
*/
unsigned int	time_lapse(struct timeval time);
void			ft_usleep(unsigned int time_wait);

/*
***TOOLS
*/
int				ft_error(char *error);
void			create_sem(t_philosopher *info);
t_philo			*create_philos(t_philosopher *infos, int i, t_philo *philo);
t_philo			*free_fork(t_philo *philo, t_philosopher *info);
void			take_fork(t_philo *philo, t_philosopher *info);

#endif
