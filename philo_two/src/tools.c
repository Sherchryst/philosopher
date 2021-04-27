/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:08:14 by sgah              #+#    #+#             */
/*   Updated: 2021/04/27 12:59:52 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int
	ft_error(char *error)
{
	fprintf(stderr, "%s\n", error);
	return (1);
}

t_philo
	create_philos(t_philosopher *infos, int i, t_philo philo)
{
	philo.info = infos;
	philo.state = 1;
	philo.id = i + 1;
	philo.eat = 0;
	philo.last_eat = 0;
	return (philo);
}

void
	take_fork(t_philo *philo, t_philosopher *info)
{
	sem_wait(info->forks);
	if (philo->info->is_dead == 0)
	{
		printf("%u %i %s\n", time_lapse(philo->info->start),
		philo->id, g_msg[FORK]);
		printf("%u %i %s\n", time_lapse(philo->info->start),
		philo->id, g_msg[FORK]);
	}
}

t_philo
	*free_fork(t_philo *philo, t_philosopher *info)
{
	sem_post(info->forks);
	return (philo);
}
