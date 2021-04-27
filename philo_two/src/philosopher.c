/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:00:21 by sgah              #+#    #+#             */
/*   Updated: 2021/04/27 14:42:55 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static void
	ft_clean(t_philosopher *info)
{
	sem_close(info->forks);
	sem_unlink("forks");
	free(info);
}

static void
	join_thread(t_philosopher *info, t_philo *philos, pthread_t *philo)
{
	unsigned int i;

	i = 0;
	while (i < info->nb_philo)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
	free(philos);
	free(philo);
	ft_clean(info);
}

static void
	monitor_philosopher(t_philosopher *info, t_philo *philos, pthread_t *philo)
{
	unsigned int i;

	gettimeofday(&info->start, NULL);
	info->begin = 1;
	i = 0;
	while (1)
	{
		usleep(200);
		if (time_lapse(info->start) - philos[i].last_eat > info->time_die)
		{
			info->is_dead++;
			printf("%u %i %s\n", time_lapse(philos[i].info->start),
			philos[i].id, g_msg[DEAD]);
			break ;
		}
		if ((unsigned int)info->limit_eat == info->nb_philo)
			break ;
		i++;
		if (i == info->nb_philo)
			i = 0;
	}
	join_thread(info, philos, philo);
}

void
	launch_philosopher(t_philosopher *info)
{
	unsigned int	i;
	t_philo			*philos;
	pthread_t		*philo;

	philo = (pthread_t*)malloc(sizeof(pthread_t) * info->nb_philo);
	philos = (t_philo*)malloc(sizeof(t_philo) * info->nb_philo);
	if (philo == NULL || philos == NULL)
		return ;
	sem_unlink("forks");
	info->forks = sem_open("forks", O_CREAT | O_EXCL, 0644, info->nb_philo / 2);
	i = 0;
	while (i < info->nb_philo)
	{
		philos[i] = create_philos(info, i, philos[i]);
		i++;
	}
	i = 0;
	while (i < info->nb_philo)
	{
		pthread_create(philo + i, NULL, philosopher, philos + i);
		i++;
	}
	monitor_philosopher(info, philos, philo);
}
