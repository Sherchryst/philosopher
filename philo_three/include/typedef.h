/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:08:46 by sgah              #+#    #+#             */
/*   Updated: 2021/04/27 20:12:54 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "philo_three.h"

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
	int				print_access;
	int				limit_eat;
	int				is_dead;
	sem_t			*forks;
	sem_t			*eat;
	sem_t			*print;
	struct timeval	start;
	sem_t			*begin;
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
