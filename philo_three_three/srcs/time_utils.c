/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frtalleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:26:59 by frtalleu          #+#    #+#             */
/*   Updated: 2021/04/06 17:06:39 by frtalleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

unsigned int
	time_lapse(struct timeval time)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (((current.tv_sec * 1000000 + current.tv_usec) -
				(time.tv_sec * 1000000 + time.tv_usec)) / 1000);
}

void
	ft_usleep(unsigned int time_wait)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	while (time_lapse(time) < time_wait)
		usleep(500);
}
