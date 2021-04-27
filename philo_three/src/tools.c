/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:08:14 by sgah              #+#    #+#             */
/*   Updated: 2021/04/27 20:33:18 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int
	ft_error(char *error)
{
	fprintf(stderr, "%s\n", error);
	return (1);
}

void
	create_sem(t_philosopher *info)
{
	sem_unlink("forks");
	sem_unlink("start");
	sem_unlink("eat");
	sem_unlink("print");
	info->forks = sem_open("forks", O_CREAT | O_EXCL, 0644, info->nb_philo / 2);
	info->eat = sem_open("eat", O_CREAT | O_EXCL, 0644, 0);
	info->begin = sem_open("start", O_CREAT | O_EXCL, 0644, 0);
	info->print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
}

t_philo
	*create_philos(t_philosopher *infos, int i, t_philo *philo)
{
	philo->info = infos;
	philo->state = 1;
	philo->id = i + 1;
	philo->eat = 0;
	philo->last_eat = 0;
	return (philo);
}
