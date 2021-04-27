/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frtalleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:21:13 by frtalleu          #+#    #+#             */
/*   Updated: 2021/04/14 15:04:11 by frtalleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"
#include "../includes/message.h"

t_philo
	*change_state(t_philo *philo, int state, t_philo_info *info)
{
	philo->state = state;
	if (philo->phil_info->is_dead != 0 || info->limit_eat == info->nb_philo)
		return (philo);
	printf("%u %i %s\n", time_lapse(philo->phil_info->start),
	philo->id, g_msg[state]);
	return (philo);
}

int
	add_eat(t_philo *philo, t_philo_info *info)
{
	if (info->limit_eat == -1)
		return (0);
	philo->eat++;
	if (philo->eat == info->nb_eat)
		info->limit_eat++;
	if (info->limit_eat == info->nb_philo)
		return (1);
	return (0);
}

t_philo
	*routine(t_philo *philo, t_philo_info *info)
{
	if (info->is_dead != 0 || info->limit_eat == info->nb_philo)
		return (philo);
	take_fork(philo, info);
	philo = change_state(philo, EAT, info);
	if (add_eat(philo, info) == 1)
		return (free_fork(philo, info));
	philo->last_eat = time_lapse(info->start);
	ft_usleep(info->time_eat);
	if (info->is_dead != 0 || info->limit_eat == info->nb_philo)
		return (free_fork(philo, info));
	philo = free_fork(philo, info);
	philo = change_state(philo, SLEEP, info);
	ft_usleep(info->time_sleep);
	if (info->is_dead != 0 || info->limit_eat == info->nb_philo)
		return (philo);
	philo = change_state(philo, THINK, info);
	return (philo);
}

void
	*make_philo(void *data)
{
	t_philo			*philo;
	t_philo_info	*info;

	philo = (t_philo *)data;
	info = philo->phil_info;
	while (info->begin != 1)
		;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (info->is_dead == 0 && info->limit_eat != info->nb_philo)
		philo = routine(philo, info);
	return (data);
}
