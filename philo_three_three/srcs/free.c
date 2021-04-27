/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frtalleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:23:00 by frtalleu          #+#    #+#             */
/*   Updated: 2021/04/16 14:27:05 by frtalleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void
	ft_free(t_philo_info *info)
{
	sem_close(info->fork);
	sem_unlink("forks");
	sem_unlink("start");
	sem_unlink("eat");
	sem_unlink("print");
	free(info);
}
