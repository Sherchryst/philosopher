/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frtalleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:45:49 by frtalleu          #+#    #+#             */
/*   Updated: 2021/04/14 14:45:50 by frtalleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

int
	ft_atois(char *str, unsigned int *j)
{
	int				i;
	unsigned int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	*j = res;
	if (str[i] != '\0')
		return (1);
	else
		return (0);
}

void
	create_sem(t_philo_info *info)
{
	sem_unlink("forks");
	sem_unlink("start");
	sem_unlink("eat");
	sem_unlink("print");
	info->fork = sem_open("forks", O_CREAT | O_EXCL, 0644, info->nb_philo / 2);
	info->eat = sem_open("eat", O_CREAT | O_EXCL, 0644, 0);
	info->begin = sem_open("start", O_CREAT | O_EXCL, 0644, 0);
	info->print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
}

t_philo_info
	*init_philo_struct(void)
{
	t_philo_info	*res;

	res = malloc(sizeof(t_philo_info));
	if (res == NULL)
		return (NULL);
	res->nb_philo = 0;
	res->time_die = 0;
	res->time_eat = 0;
	res->time_sleep = 0;
	res->nb_eat = 0;
	res->is_dead = 0;
	res->begin = 0;
	res->print_access = 0;
	return (res);
}

t_philo
	*create_philos_struct(t_philo_info *infos, int i, t_philo *philo)
{
	philo->phil_info = infos;
	philo->state = 1;
	philo->id = i + 1;
	philo->eat = 0;
	philo->last_eat = 0;
	return (philo);
}
