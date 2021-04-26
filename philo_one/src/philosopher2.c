/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:03:23 by sgah              #+#    #+#             */
/*   Updated: 2021/04/26 20:14:23 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_philo
	*change_state(t_philo *philo, int state, t_philosopher *info)
{
	philo->state = state;
	if (philo->info->is_dead != 0 ||
	(unsigned int)info->limit_eat == info->nb_philo)
		return (philo);
	printf("%u %i %s\n", time_lapse(philo->info->start),
	philo->id, g_msg[state]);
	return (philo);
}

int
	add_eat(t_philo *philo, t_philosopher *info)
{
	if (info->limit_eat == -1)
		return (0);
	philo->eat++;
	if ((unsigned int)philo->eat == info->nb_eat)
		info->limit_eat++;
	if ((unsigned int)info->limit_eat == info->nb_philo)
		return (1);
	return (0);
}

t_philo
	*routine(t_philo *philo, t_philosopher *info)
{
	while (philo->fork_l->free_fork == 1 && philo->fork_r->free_fork == 1)
		;
	if (info->is_dead != 0 || info->limit_eat == (int)info->nb_philo)
		return (philo);
	take_fork(philo);
	philo = change_state(philo, EAT, info);
	if (add_eat(philo, info) == 1)
		return (free_fork(philo));
	philo->last_eat = time_lapse(info->start);
	ft_usleep(info->time_eat);
	if (info->is_dead != 0 || info->limit_eat == (int)info->nb_philo)
		return (free_fork(philo));
	philo = free_fork(philo);
	philo = change_state(philo, SLEEP, info);
	ft_usleep(info->time_sleep);
	if (info->is_dead != 0 || info->limit_eat == (int)info->nb_philo)
		return (philo);
	philo = change_state(philo, THINK, info);
	return (philo);
}

void
	*philosopher(void *data)
{
	t_philo			*philo;
	t_philosopher	*info;

	philo = (t_philo *)data;
	info = philo->info;
	while (info->begin != 1)
		;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (info->is_dead == 0 && info->limit_eat != (int)info->nb_philo)
		philo = routine(philo, info);
	return (data);
}
