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

#include "../includes/philo_three.h"

t_philo
	*change_state(t_philo *philo, int state, t_philo_info *info)
{
	philo->state = state;
	sem_wait(info->print);
	aff(philo, state);
	sem_post(info->print);
	return (philo);
}

int
	add_eat(t_philo *philo, t_philo_info *info)
{
	if (info->limit_eat == -1)
		return (0);
	philo->eat++;
	if (philo->eat == (int)info->nb_eat)
		sem_post(info->eat);
	if (info->limit_eat == (int)info->nb_philo)
		return (1);
	return (0);
}

t_philo
	*routine(t_philo *philo, t_philo_info *info)
{
	if (info->is_dead != 0)
		return (philo);
	take_fork(philo, info);
	philo = change_state(philo, EAT, info);
	if (add_eat(philo, info) == 1)
		return (free_fork(philo, info));
	philo->last_eat = time_lapse(info->start) + 0;
	ft_usleep(info->time_eat);
	if (info->is_dead != 0)
		return (free_fork(philo, info));
	philo = free_fork(philo, info);
	philo = change_state(philo, SLEEP, info);
	ft_usleep(info->time_sleep);
	if (info->is_dead != 0)
		return (philo);
	philo = change_state(philo, THINK, info);
	return (philo);
}

void
	*monitoring(void *data)
{
	t_philo			*philo;
	t_philo_info	*info;
	int				i;

	i = 0;
	philo = (t_philo *)data;
	info = philo->phil_info;
	while (1)
	{
		usleep(1000);
		if (time_lapse(info->start) - philo->last_eat >= info->time_die)
		{
			sem_wait(info->print);
			aff(philo, DEAD);
			info->is_dead++;
			break ;
		}
	}
	while (i < (int)info->nb_philo)
	{
		i++;
		sem_post(info->eat);
	}
	return (data);
}

void
	make_philo(t_philo *philo)
{
	t_philo_info	*info;
	pthread_t		*monitor;

	monitor = malloc(sizeof(pthread_t));
	if (monitor == NULL)
		return ;
	info = philo->phil_info;
	sem_wait(info->begin);
	gettimeofday(&info->start, NULL);
	pthread_create(monitor, NULL, monitoring, philo);
	if (philo->id % 2 == 0)
		usleep(1000);
	while (info->is_dead == 0)
		philo = routine(philo, info);
}
