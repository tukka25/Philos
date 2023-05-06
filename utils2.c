/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:29:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/04 18:01:58 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks(t_forks *f, int index)
{
	pthread_mutex_lock(&f->fork);
	if (f->forks[index] != '\0')
	{
		pthread_mutex_unlock(&f->fork);
		pthread_mutex_lock(&f->mutex[index - 1]);
		pthread_mutex_lock(&f->mutex[index]);
		pthread_mutex_lock(&f->fork);
		f->forks[index - 1] = -1;
		f->forks[index] = -1;
		pthread_mutex_unlock(&f->fork);
	}
	else
	{
		pthread_mutex_unlock(&f->fork);
		pthread_mutex_lock(&f->mutex[0]);
		pthread_mutex_lock(&f->mutex[index - 1]);
		pthread_mutex_lock(&f->fork);
		f->forks[0] = -1;
		f->forks[index - 1] = -1;
		pthread_mutex_unlock(&f->fork);
	}
}

int	check_for_forks(t_forks *f, int index)
{
	int		i;

	pthread_mutex_lock(&f->fork);
	i = 0;
	if (f->forks[index] != '\0')
	{
		if (f->forks[index] != -1 && f->forks[index - 1] != -1)
		{
			i = 1;
		}
	}
	else
	{
		if (f->forks[0] != -1 && (f->forks[index - 1] != -1
				&& f->forks[index - 1] != 0))
		{
			i = 1;
		}
	}
	pthread_mutex_unlock(&f->fork);
	return (i);
}

void	return_forks(t_forks *f, int index)
{
	pthread_mutex_lock(&f->fork);
	if (f->forks[index] != '\0')
	{
		f->forks[index - 1] = index;
		f->forks[index] = index + 1;
		pthread_mutex_unlock(&f->fork);
		pthread_mutex_unlock(&f->mutex[index - 1]);
		pthread_mutex_unlock(&f->mutex[index]);
	}
	else
	{
		f->forks[0] = 1;
		f->forks[index - 1] = index;
		pthread_mutex_unlock(&f->fork);
		pthread_mutex_unlock(&f->mutex[0]);
		pthread_mutex_unlock(&f->mutex[index - 1]);
	}
}

void	ft_usleep(t_thread *p, int l)
{
	long long	time;
	long long	time2;

	gettimeofday(&p->tv, NULL);
	time2 = p->tv.tv_sec * 1000;
	time2 += p->tv.tv_usec / 1000;
	time = time2;
	while (time - time2 < l)
	{
		if (check_if_died(p) == 1)
			return ;
		gettimeofday(&p->tv, NULL);
		time = p->tv.tv_sec * 1000;
		time += p->tv.tv_usec / 1000;
		usleep(100);
	}
	// usleep(10);
}

long long	ft_gettime(void)
{
	long long		t;
	struct timeval	tv;

	t = 0;
	gettimeofday(&tv, NULL);
	t = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (t);
}
