/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:23:37 by sgah              #+#    #+#             */
/*   Updated: 2021/04/22 19:03:43 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void
	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork->fork);
	pthread_mutex_lock(philo->r_fork->fork);
	philo->l_fork->free_fork = 1;
	philo->r_fork->free_fork = 1;
	if (philo->info_philo->is_dead == 0)
	{
		printf("%u %i %s\n", time_lapse(philo->info_philo->start),
		philo->id, g_msg[FORK]);
		printf("%u %i %s\n", time_lapse(philo->info_philo->start),
		philo->id, g_msg[FORK]);
	}
}

t_philo
	*free_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork->fork);
	pthread_mutex_unlock(philo->r_fork->fork);
	philo->l_fork->free_fork = 0;
	philo->r_fork->free_fork = 0;
	return (philo);
}

void
	ft_free(t_philosopher *info)
{
	int i;

	i = 0;
	while (i < info->nb_philo)
	{
		free(info->forks[i].fork);
		i++;
	}
	free(info->print);
	free(info->forks);
	free(info);
}
