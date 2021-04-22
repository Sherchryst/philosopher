/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:25:33 by sgah              #+#    #+#             */
/*   Updated: 2021/04/22 15:27:03 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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
