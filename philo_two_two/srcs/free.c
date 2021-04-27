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

#include "../includes/philo_two.h"

void
	ft_free(t_philo_info *info)
{
	sem_close(info->fork);
	sem_unlink("fork");
	free(info);
}
