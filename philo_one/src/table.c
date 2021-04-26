/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:11:57 by sgah              #+#    #+#             */
/*   Updated: 2021/04/26 18:07:21 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_philo
	take_a_seat(t_philosopher *table, int place, t_philo philo)
{
	philo.info_philo = table;
	philo.state = 1;
	philo.id = place + 1;
	philo.eat = 0;
	philo.r_fork = &table->forks[place];
	philo.last_eat = 0;
	if (place + 1 == table->nb_philo)
		philo.l_fork = &table->forks[0];
	else
		philo.l_fork = &table->forks[place + 1];
	return (philo);
}

t_fork
	*share_the_forks(t_philosopher *table)
{
	int		i;
	t_fork	*forks;

	i = 0;
	forks = (t_fork*)malloc(sizeof(t_fork) * table->nb_philo);
	if (forks == NULL)
		return (NULL);
	pthread_mutex_init(table->print, NULL);
	while (i < table->nb_philo)
	{
		forks[i].fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(forks[i].fork, NULL);
		forks[i].free_fork = 0;
		i++;
	}
	return (forks);
}

int
	set_the_table(t_philosopher **table)
{
	(*table) = (t_philosopher*)malloc(sizeof(t_philosopher));
	if (*table == NULL)
		return (-1);
	(*table)->print = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
	if ((*table)->print == NULL)
		return (-1);
	(*table)->nb_philo = 0;
	(*table)->time_die = 0;
	(*table)->time_eat = 0;
	(*table)->time_sleep = 0;
	(*table)->nb_eat = 0;
	(*table)->is_dead = 0;
	(*table)->begin = 0;
	(*table)->print_access = 0;
	(*table)->err_arg = 0;
	return (0);
}

int
	get_philo_info(t_philosopher *table, int ac, char **av)
{
	table->nb_philo = get_value(av[1]);
	if (table->nb_philo == -1)
		return (-1);
	table->time_die = get_value(av[2]);
	if (table->time_die == -1)
		return (-1);
	table->time_eat = get_value(av[3]);
	if (table->time_eat == -1)
		return (-1);
	table->time_sleep = get_value(av[4]);
	if (table->time_sleep == -1)
		return (-1);
	if (ac == 6)
	{
		table->nb_eat = get_value(av[5]);
		if (table->nb_eat == -1)
			return (-1);
		table->limit_eat = 0;
	}
	else
	{
		table->nb_eat = 0;
		table->limit_eat = -1;
	}
	return (0);
}
