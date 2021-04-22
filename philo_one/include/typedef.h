/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:08:46 by sgah              #+#    #+#             */
/*   Updated: 2021/04/22 18:12:40 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "philo_one.h"

static const char	*g_msg[5] =
{
	"died",
	"is thinking",
	"is eating",
	"is sleeping",
	"has taken a fork"
};

typedef struct		s_fork
{
	pthread_mutex_t	*fork;
	int				free_fork;
}					t_fork;

typedef struct		s_philosopher
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	int				is_dead;
	int				limit_eat;
	int				begin;
	pthread_mutex_t	*print;
	t_fork			*forks;
	int				print_access;
	struct timeval	start;
	int				err_arg;
}					t_philosopher;

typedef struct		s_philo
{
	t_philosopher	*info_philo;
	int				state;
	int				id;
	int				eat;
	int				last_eat;
	t_fork			*r_fork;
	t_fork			*l_fork;
}					t_philo;

#endif
