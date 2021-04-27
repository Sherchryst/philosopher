/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:19:47 by sgah              #+#    #+#             */
/*   Updated: 2021/04/27 23:34:28 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void
	ft_bzero(void *s, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char*)s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}

void
	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *ptr;
	unsigned char *pt;

	ptr = (unsigned char *)dest;
	pt = (unsigned char *)src;
	if (dest == src)
		return (dest);
	while (n-- > 0)
	{
		*ptr = *pt;
		pt++;
		ptr++;
	}
	return (dest);
}

int
	add_time(char *buff, unsigned int time)
{
	int				i;
	int				res;
	unsigned int	tmp;

	if (time == 0)
		buff[0] = '0';
	if (time == 0)
		return (1);
	tmp = time;
	i = 0;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		i++;
	}
	res = i;
	while (time >= 10)
	{
		i--;
		buff[i] = (time % 10) + 48;
		time = time / 10;
	}
	i--;
	buff[i] = time + 48;
	return (res);
}

size_t
	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void
	display_philo(t_philo *philo, int state)
{
	char	buff[33];
	int		i;

	ft_bzero(buff, 33);
	i = add_time(buff, time_lapse(philo->info->start));
	buff[i] = ' ';
	i++;
	i = i + add_time(&buff[i], (unsigned int)philo->id);
	buff[i] = ' ';
	i++;
	ft_memcpy(&buff[i], g_msg[state], ft_strlen(g_msg[state]));
	i = i + strlen(g_msg[state]);
	buff[i] = '\n';
	i++;
	write(1, buff, i);
}
