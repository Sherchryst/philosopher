/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:46:56 by sgah              #+#    #+#             */
/*   Updated: 2021/04/22 17:17:09 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int
	init_dinner(t_philosopher *table)
{
	int			i;
	t_philo		*philos;
	pthread_t	*plate;

	plate = (pthread_t*)malloc(sizeof(pthread_t) * table->nb_philo);
	philos = (t_philo*)malloc(sizeof(t_philo) * table->nb_philo);
	if (plate == NULL || philos == NULL)
		return ;
	i = -1;
	share_the_forks(table, &table->forks);
	while (++i < table->nb_philo)
		take_a_seat(table, &(philos[i]), i);
	i = -1;
	while (++i < table->nb_philo)
		pthread_create(plate + i, NULL, )
}

