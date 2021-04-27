/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:08:46 by sgah              #+#    #+#             */
/*   Updated: 2021/04/27 12:27:34 by sgah             ###   ########.fr       */
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

typedef struct		s_philosopher
{
	unsigned int	nb_philo;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	unsigned int	nb_eat;
	int				is_dead;
	int				limit_eat;
	int				begin;
	sem_t			*forks;
	int				print_access;
	struct timeval	start;
}					t_philosopher;

typedef struct		s_philo
{
	t_philosopher	*info;
	int				state;
	int				id;
	int				eat;
	unsigned int	last_eat;
}					t_philo;

#endif
