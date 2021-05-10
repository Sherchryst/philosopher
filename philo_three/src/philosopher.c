/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:00:21 by sgah              #+#    #+#             */
/*   Updated: 2021/05/10 15:30:17 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void
	ft_clean(t_philosopher *info)
{
	sem_close(info->begin);
	sem_close(info->print);
	sem_close(info->eat);
	sem_close(info->forks);
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("start");
	sem_unlink("eat");
	free(info);
}

static void
	monitor_philosopher(t_philosopher *info, pid_t id[])
{
	unsigned int	i;

	i = 0;
	while (i < info->nb_philo)
	{
		sem_post(info->begin);
		i++;
	}
	i = 0;
	while (i < info->nb_philo)
	{
		sem_wait(info->eat);
		i++;
	}
	i = 0;
	while (i < info->nb_philo)
	{
		kill(id[i], 9);
		waitpid(id[i], NULL, 0);
		i++;
	}
	ft_clean(info);
}

void
	launch_philosopher(t_philosopher *info)
{
	unsigned int	i;
	t_philo			*philo;
	pid_t			*id;

	id = (pid_t*)malloc(sizeof(pid_t) * info->nb_philo);
	philo = (t_philo*)malloc(sizeof(t_philo));
	if (philo == NULL || id == NULL)
		return ;
	create_sem(info);
	i = 0;
	while (i < info->nb_philo)
	{
		id[i] = fork();
		if (id[i] == 0)
		{
			philo = create_philos(info, i, philo);
			break ;
		}
		i++;
	}
	if (i == info->nb_philo)
		i--;
	(id[i] != 0) ? monitor_philosopher(info, id) : philosopher(philo);
	free(philo);
	free(id);
}
