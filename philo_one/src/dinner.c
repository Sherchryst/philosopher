/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:46:56 by sgah              #+#    #+#             */
/*   Updated: 2021/04/22 15:27:10 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int
	have_an_aperitif(t_philosopher *table)
{
	int			i;
	t_philo		*philos;
	pthread_t	*plate;

	plate = (pthread_t*)malloc(sizeof(pthread_t) * table->nb_philo);
	philos = (t_philo*)malloc(sizeof(t_philo) * table->nb_philo);
	if (plate == NULL || philos == NULL)
		return ;
	i = -1;
}

