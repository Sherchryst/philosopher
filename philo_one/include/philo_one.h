/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:54:28 by sgah              #+#    #+#             */
/*   Updated: 2021/04/22 17:17:09 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <time.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# include "typedef.h"

/*
***TABLE
*/
int				set_the_table(t_philosopher **table);
int				go_around_the_table(t_philosopher *table, int ac, char **av);
int				share_the_forks(t_philosopher *table, t_fork **forks);
void			take_a_seat(t_philosopher *table, t_philo *philo, int place);

/*
***TOOLS
*/
int				endofdinner(t_philosopher *philo_info);
int				get_value(char *val);

#endif
