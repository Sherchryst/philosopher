/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:08:14 by sgah              #+#    #+#             */
/*   Updated: 2021/04/26 20:14:23 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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
	philo.fork_r = &infos->forks[i];
	philo.last_eat = 0;
	if (i + 1 == (int)infos->nb_philo)
		philo.fork_l = &infos->forks[0];
	else
		philo.fork_l = &infos->forks[i + 1];
	return (philo);
}

t_fork
	*init_mutex(t_philosopher *info)
{
	t_fork			*fork_philo;
	unsigned int	i;

	i = 0;
	fork_philo = (t_fork*)malloc(sizeof(t_fork) * info->nb_philo);
	if (fork_philo == NULL)
		return (NULL);
	pthread_mutex_init(info->print, NULL);
	while (i < info->nb_philo)
	{
		fork_philo[i].fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(fork_philo[i].fork, NULL);
		fork_philo[i].free_fork = 0;
		i++;
	}
	return (fork_philo);
}

void
	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l->fork);
	pthread_mutex_lock(philo->fork_r->fork);
	philo->fork_l->free_fork = 1;
	philo->fork_r->free_fork = 1;
	if (philo->info->is_dead == 0)
	{
		printf("%u %i %s\n", time_lapse(philo->info->start),
		philo->id, g_msg[FORK]);
		printf("%u %i %s\n", time_lapse(philo->info->start),
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
