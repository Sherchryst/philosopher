/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:53:57 by sgah              #+#    #+#             */
/*   Updated: 2021/04/25 19:23:55 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int
	main(int ac, char **av)
{
	t_philosopher	*table;

	if (ac != 5 && ac != 6)
		return (-1);
	if (set_the_table(&table) < 0)
		return (endofdinner(table));
	if (get_philo_info(table, ac, av) < 0 ||
		table->nb_philo <= 1)
	{
		table->err_arg = 1;
		return (endofdinner(table));
	}
	init_dinner(table);
	return (0);
}
