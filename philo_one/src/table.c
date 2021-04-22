/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:11:57 by sgah              #+#    #+#             */
/*   Updated: 2021/04/22 12:23:46 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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
	go_around_the_table(t_philosopher *table, int ac, char **av)
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
