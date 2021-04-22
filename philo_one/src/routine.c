/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:23:05 by sgah              #+#    #+#             */
/*   Updated: 2021/04/22 18:04:55 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"



void
	*init_routine(void *data)
{
	t_philo			*philo;
	t_philosopher	*table;

	philo = (t_philo *)data;
	table = philo->info_philo;
	while (table->begin != 1)
		0;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (table->is_dead == 0 && table->limit_eat != table->nb_philo)
		routine(&philo, table);
	return (data);
}
