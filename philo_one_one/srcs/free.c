/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frtalleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:23:00 by frtalleu          #+#    #+#             */
/*   Updated: 2021/04/14 15:23:01 by frtalleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void
	ft_free(t_philo_info *info)
{
	unsigned int i;

	i = 0;
	while (i < info->nb_philo)
	{
		free(info->forks[i].fork);
		i++;
	}
	free(info->print);
	free(info->forks);
	free(info);
}
