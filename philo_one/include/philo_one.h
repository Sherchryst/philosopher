/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:54:28 by sgah              #+#    #+#             */
/*   Updated: 2021/04/23 22:18:18 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# define DEAD	0
# define THINK	1
# define EAT	2
# define SLEEP	3
# define FORK	4

# include <time.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# include "typedef.h"

/*
***DINNER
*/
void			init_dinner(t_philosopher *table);

/*
***TABLE
*/
int				set_the_table(t_philosopher **table);
int				go_around_the_table(t_philosopher *table, int ac, char **av);
t_fork			*share_the_forks(t_philosopher *table);
void			take_a_seat(t_philosopher *table, t_philo *philo, int place);

/*
***ROUTINE
*/
void			*init_routine(void *data);

/*
***TOOLS
*/
int				endofdinner(t_philosopher *philo_info);
int				get_value(char *val);
unsigned int	time_lapse(struct timeval time);
void			ft_usleep(unsigned int time_wait);
void			take_fork(t_philo *philo);
t_philo			*free_fork(t_philo *philo);
void			ft_free(t_philosopher *info);

#endif
