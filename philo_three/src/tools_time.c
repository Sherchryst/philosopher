/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:06:18 by sgah              #+#    #+#             */
/*   Updated: 2021/04/27 20:16:58 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
