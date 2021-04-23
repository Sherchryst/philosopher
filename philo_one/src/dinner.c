/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:46:56 by sgah              #+#    #+#             */
/*   Updated: 2021/04/23 20:49:31 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void
	join_thread(t_philosopher *table, t_philo *philos, pthread_t *plate)
{
	int i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_join(plate[i], NULL);
		i++;
	}
	free(philos);
	free(plate);
	ft_free(table);
}

void
	manage_dinner(t_philosopher *table, t_philo *philos, pthread_t *plate)
{
	int i;

	gettimeofday(&table->start, NULL);
	table->begin = 1;
	i = 0;
	while (1)
	{
		usleep(200);
		if ((int)time_lapse(table->start) - philos[i].last_eat > table->time_die)
		{
			table->is_dead++;
			printf("%u %i %s\n", time_lapse(philos[i].info_philo->start),
			philos[i].id, g_msg[DEAD]);
			printf("ici\n");
			break ;
		}
		if (table->limit_eat == table->nb_philo)
			break ;
		i++;
		if (i == table->nb_philo)
			i = 0;
	}
	join_thread(table, philos, plate);
}

void
	init_dinner(t_philosopher *table)
{
	int			i;
	t_philo		*philos;
	pthread_t	*plate;

	plate = (pthread_t*)malloc(sizeof(pthread_t) * table->nb_philo);
	philos = (t_philo*)malloc(sizeof(t_philo) * table->nb_philo);
	if (plate == NULL || philos == NULL)
		return ;
	share_the_forks(table, &table->forks);
	i = -1;
	while (++i < table->nb_philo)
		take_a_seat(table, &(philos[i]), i);
	i = -1;
	while (++i < table->nb_philo)
		pthread_create(plate + i, NULL, init_routine, philos + i);
	manage_dinner(table, philos, plate);
}

