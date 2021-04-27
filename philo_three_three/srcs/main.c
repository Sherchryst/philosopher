/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frtalleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:35:08 by frtalleu          #+#    #+#             */
/*   Updated: 2021/04/19 15:41:39 by frtalleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"
#include "../includes/message.h"

void
	free_all(t_philo_info *info)
{
	sem_close(info->fork);
	sem_close(info->begin);
	sem_close(info->print);
	sem_close(info->eat);
	ft_free(info);
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("start");
	sem_unlink("eat");
}

void
	monitor_simulation(t_philo_info *info, pid_t id[])
{
	int i;

	i = 0;
	while (i < (int)info->nb_philo)
	{
		sem_post(info->begin);
		i++;
	}
	i = 0;
	while (i < (int)info->nb_philo)
	{
		sem_wait(info->eat);
		i++;
	}
	i = 0;
	while (i < (int)info->nb_philo)
	{
		kill(id[i], 9);
		waitpid(id[i], NULL, 0);
		i++;
	}
	free_all(info);
}

void
	launch_simulation(t_philo_info *info)
{
	int			i;
	t_philo		*philo;
	pid_t		id[info->nb_philo];

	if (!(philo = malloc(sizeof(t_philo))))
		return ;
	i = 0;
	create_sem(info);
	while (i < (int)info->nb_philo)
	{
		id[i] = fork();
		if (id[i] == 0)
		{
			philo = create_philos_struct(info, i, philo);
			break ;
		}
		i++;
	}
	if (i == (int)info->nb_philo)
		i--;
	if (id[i] != 0)
		monitor_simulation(info, id);
	else
		make_philo(philo);
	free(philo);
}

int
	ft_end(t_philo_info *info)
{
	if (info->nb_philo == 1)
		printf("%u 1 %s\n", info->time_die, g_msg[DEAD]);
	else
		printf("error in arguments");
	free(info);
	return (0);
}

int
	main(int ac, char **av)
{
	int				err;
	t_philo_info	*info;

	info = init_philo_struct();
	err = 0;
	if (ac != 5 && ac != 6)
		return (ft_end(info));
	err = ft_atois(av[1], &info->nb_philo);
	err = ft_atois(av[2], &info->time_die);
	err = ft_atois(av[3], &info->time_eat);
	err = ft_atois(av[4], &info->time_sleep);
	if (ac == 6)
	{
		err = ft_atois(av[5], &info->nb_eat);
		info->limit_eat = 0;
	}
	else
	{
		info->nb_eat = 0;
		info->limit_eat = -1;
	}
	if (err != 0 || info->nb_philo <= 1)
		return (ft_end(info));
	launch_simulation(info);
}
