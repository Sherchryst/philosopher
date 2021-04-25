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

#include "../includes/philo_one.h"

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

t_philo_info
	*init_philo_struct(void)
{
	t_philo_info	*res;

	res = malloc(sizeof(t_philo_info));
	if (res == NULL)
		return (NULL);
	res->print = malloc(sizeof(pthread_mutex_t));
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

t_fork
	*create_mutex(t_philo_info *info)
{
	t_fork			*fork_philo;
	unsigned int	i;

	i = 0;
	fork_philo = malloc(sizeof(t_fork) * info->nb_philo);
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

t_philo
	create_philos_struct(t_philo_info *infos, int i, t_philo philo)
{
	philo.phil_info = infos;
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
