/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frtalleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:15:33 by frtalleu          #+#    #+#             */
/*   Updated: 2021/04/13 15:15:35 by frtalleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"
#include "../includes/message.h"

void
	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l->fork);
	pthread_mutex_lock(philo->fork_r->fork);
	philo->fork_l->free_fork = 1;
	philo->fork_r->free_fork = 1;
	if (philo->phil_info->is_dead == 0)
	{
		printf("%u %i %s\n", time_lapse(philo->phil_info->start),
		philo->id, g_msg[FORK]);
		printf("%u %i %s\n", time_lapse(philo->phil_info->start),
		philo->id, g_msg[FORK]);
	}
}

t_philo
	*free_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_l->fork);
	pthread_mutex_unlock(philo->fork_r->fork);
	philo->fork_l->free_fork = 0;
	philo->fork_r->free_fork = 0;
	return (philo);
}
