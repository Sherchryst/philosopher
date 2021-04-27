/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frtalleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:15:33 by frtalleu          #+#    #+#             */
/*   Updated: 2021/04/13 15:15:35 by frtalleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"
#include "../includes/message.h"

void
	take_fork(t_philo *philo, t_philo_info *info)
{
	sem_wait(info->fork);
	if (philo->phil_info->is_dead == 0)
	{
		printf("%u %i %s\n", time_lapse(philo->phil_info->start),
		philo->id, g_msg[FORK]);
		printf("%u %i %s\n", time_lapse(philo->phil_info->start),
		philo->id, g_msg[FORK]);
	}
}

t_philo
	*free_fork(t_philo *philo, t_philo_info *info)
{
	sem_post(info->fork);
	return (philo);
}
