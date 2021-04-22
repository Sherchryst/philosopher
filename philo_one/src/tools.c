/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:25:33 by sgah              #+#    #+#             */
/*   Updated: 2021/04/22 18:22:37 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void
	ft_usleep(unsigned int time_wait)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	while (time_lapse(time) < time_wait)
		usleep(500);
}

unsigned int
	time_lapse(struct timeval time)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (((current.tv_sec * 1000000 + current.tv_usec) -
				(time.tv_sec * 1000000 + time.tv_usec)) / 1000);
}

int
	get_value(char *val)
{
	unsigned int	res;
	int				i;

	i = 0;
	res = 0;
	while (val[i] >= '0' && val[i] <= '9')
	{
		res = res * 10 + (val[i] - '0');
		i++;
	}
	return ((val[i] == '\0') ? res : -1);
}

int
	endofdinner(t_philosopher *philo_info)
{
	if (philo_info != NULL)
	{
		if (philo_info->print != NULL)
			free(philo_info->print);
		else
			return (-1);
		if (philo_info->nb_philo == 1)
			printf("he stayed forever alone: ");
		if (philo_info->err_arg == 1)
			printf("error arguments\n");
		free(philo_info);
	}
	else
		return (-1);
	return (0);
}
