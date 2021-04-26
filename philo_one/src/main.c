/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:53:57 by sgah              #+#    #+#             */
/*   Updated: 2021/04/26 20:25:29 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int
	init_philosopher(t_philosopher **info)
{
	(*info) = (t_philosopher*)malloc(sizeof(t_philosopher));
	if ((*info) == NULL)
		return (1);
	(*info)->print = malloc(sizeof(pthread_mutex_t));
	(*info)->nb_philo = 0;
	(*info)->time_die = 0;
	(*info)->time_eat = 0;
	(*info)->time_sleep = 0;
	(*info)->nb_eat = 0;
	(*info)->is_dead = 0;
	(*info)->begin = 0;
	(*info)->print_access = 0;
	return (0);
}

int
	get_value(char *str)
{
	unsigned int	ret;
	int				i;

	ret = 0;
	i = -1;
	while (str[++i] >= '0' && str[i] <= '9')
		ret = ret * 10 + (str[i] - '0');
	return ((str[i] == '\0') ? ret : 0);
}

int
	get_philosopher(t_philosopher **info, int ac, char **av)
{
	if (((*info)->nb_philo = get_value(av[1])) == 0)
		return (1);
	if (((*info)->time_die = get_value(av[2])) == 0)
		return (1);
	if (((*info)->time_eat = get_value(av[3])) == 0)
		return (1);
	if (((*info)->time_sleep = get_value(av[4])) == 0)
		return (1);
	if (ac == 6)
	{
		if (((*info)->nb_eat = get_value(av[5])) == 0)
			return (1);
		(*info)->limit_eat = 0;
	}
	else
	{
		(*info)->nb_eat = 0;
		(*info)->limit_eat = -1;
	}
	return (0);
}

int
	endofprog(t_philosopher *info)
{
	if (info->nb_philo == 1)
		fprintf(stderr, "%s", "he stayed forever alone: ");
	free(info->print);
	free(info);
	return (ft_error("error in arguments"));
}

int
	main(int ac, char **av)
{
	t_philosopher	*info;

	if (ac != 5 && ac != 6)
		return (ft_error("wrong number of argument"));
	if (init_philosopher(&info) == 1)
		return (ft_error("memory allocation failed"));
	if (get_philosopher(&info, ac, av) == 1 || info->nb_philo <= 1)
		return (endofprog(info));
	launch_philosopher(info);
}
