/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:23:05 by sgah              #+#    #+#             */
/*   Updated: 2021/04/22 18:57:10 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_philo
	*change_state(t_philo *philo, int state, t_philosopher *table)
{
	philo->state = state;
	if (philo->info_philo->is_dead != 0 ||
		table->limit_eat == table->nb_philo)
		return (philo);
	printf("%u %i %s\n", time_lapse(philo->info_philo->start),
	philo->id, g_msg[state]);
	return (philo);
}

int
	add_eat(t_philo *philo, t_philosopher *table)
{
	if (table->limit_eat == -1)
		return (0);
	philo->eat++;
	if (philo->eat == table->nb_eat)
		table->limit_eat++;
	if (table->limit_eat == table->nb_philo)
		return (1);
	return (0);
}

t_philo
	*routine(t_philo *philo, t_philosopher *table)
{
	while (philo->l_fork->free_fork == 1 && philo->r_fork->free_fork == 1)
		;
	if (table->is_dead != 0 || table->limit_eat == table->nb_philo)
		return (philo);
	take_fork(philo);
	philo = change_state(philo, EAT, table);
	if (add_eat(philo, table) == 1)
		return (free_fork(philo));
	philo->last_eat = (int)time_lapse(table->start);
	ft_usleep((unsigned int)table->time_eat);
	if (table->is_dead != 0 || table->limit_eat == table->nb_philo)
		return (free_fork(philo));
	philo = free_fork(philo);
	philo = change_state(philo, SLEEP, table);
	ft_usleep((unsigned int)table->time_sleep);
	if (table->is_dead != 0 || table->limit_eat == table->nb_philo)
		return (philo);
	philo = change_state(philo, THINK, table);
	return (philo);
}

void
	*init_routine(void *data)
{
	t_philo			*philo;
	t_philosopher	*table;

	philo = (t_philo *)data;
	table = philo->info_philo;
	while (table->begin != 1)
		;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (table->is_dead == 0 && table->limit_eat != table->nb_philo)
		philo = routine(philo, table);
	return (data);
}
