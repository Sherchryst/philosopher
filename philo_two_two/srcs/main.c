/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frtalleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:35:08 by frtalleu          #+#    #+#             */
/*   Updated: 2021/03/31 11:35:09 by frtalleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"
#include "../includes/message.h"

void
	join_thread(t_philo_info *info, t_philo *philos, pthread_t *philo)
{
	int i;

	i = 0;
	while (i < info->nb_philo)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
	free(philos);
	free(philo);
	ft_free(info);
}

void
	monitor_simulation(t_philo_info *info, t_philo *philos, pthread_t *philo)
{
	int i;

	gettimeofday(&info->start, NULL);
	info->begin = 1;
	i = 0;
	while (1)
	{
		usleep(200);
		if (time_lapse(info->start) - philos[i].last_eat > info->time_die)
		{
			info->is_dead++;
			printf("%u %i %s\n", time_lapse(philos[i].phil_info->start),
			philos[i].id, g_msg[DEAD]);
			break ;
		}
		if (info->limit_eat == info->nb_philo)
			break ;
		i++;
		if (i == info->nb_philo)
			i = 0;
	}
	join_thread(info, philos, philo);
}

void
	launch_simulation(t_philo_info *info)
{
	int			i;
	t_philo		*philos;
	pthread_t	*philo;

	philo = malloc(sizeof(pthread_t) * info->nb_philo);
	philos = malloc(sizeof(t_philo) * info->nb_philo);
	if (philos == NULL)
		return ;
	i = 0;
	sem_unlink("forks");
	info->fork = sem_open("forks", O_CREAT | O_EXCL, 0644, info->nb_philo / 2);
	while (i < info->nb_philo)
	{
		philos[i] = create_philos_struct(info, i, philos[i]);
		i++;
	}
	i = 0;
	while (i < info->nb_philo)
	{
		pthread_create(philo + i, NULL, make_philo, philos + i);
		i++;
	}
	monitor_simulation(info, philos, philo);
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
		return (0);
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
