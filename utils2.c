/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:29:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/26 17:44:48 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks(t_forks *f, int index)
{
	if (f->forks[index] != '\0')
	{
		f->forks[index - 1] = -1;
		f->forks[index] = -1;
		pthread_mutex_lock(&f->mutex[index - 1]);
		pthread_mutex_lock(&f->mutex[index]);
	}
	else
	{
		f->forks[0] = -1;
		f->forks[index - 1] = -1;
		pthread_mutex_lock(&f->mutex[0]);
		pthread_mutex_lock(&f->mutex[index - 1]);
	}
	// }
	// printf("\n");
	// int s = 0;
	// while (f->forks[s])
	// {
	// 	printf("  {%d}  ", f->forks[s]);
	// 	s++;
	// }
	// printf("\n");
}

int	check_for_forks(t_forks *f, int index)
{
	// printf("index = %d\n", index);
	// sleep(2); /
	// printf("fork = %d", f->forks[index]);
	if (f->forks[index] != '\0')
	{
		if (f->forks[index] != -1 && f->forks[index - 1] != -1)
		{
			// printf("in = %d\n", f->forks[index]);
			// printf("in = %d\n", f->forks[index - 1]);
			// printf("index1 = %d\n", index);
			return (1);
		}
		return (0);
	}
	else
	{
		if (f->forks[0] != -1 && (f->forks[index - 1] != -1
			&& f->forks[index - 1] != 0))
		{
			// printf("index2 = %d\n", index);
			return (1);
		}
		return (0);
	}
	return (0);
}

void	return_forks(t_forks *f, int index)
{
	// write(1, "return\n", 7);
	// sleep(2);
	if (f->forks[index] != '\0')
	{
		// if (f->forks[index - 1] != -1 && f->forks[index] != -1)
		// {
			f->forks[index - 1] = index;
			f->forks[index] = index + 1;
			// pthread_mutex_unlock(&f->mu);
			pthread_mutex_unlock(&f->mutex[index - 1]);
			pthread_mutex_unlock(&f->mutex[index]);
		// }
		// printf("\n");
		// int s = 0;
		// while (f->forks[s])
		// {
		// 	printf("  [%d]  ", f->forks[s]);
		// 	s++;
		// }
		// printf("\n");
		// sleep(2);
	}
	else
	{
		// if (f->forks[0] != -1 && f->forks[index - 1] != -1)
		// {
			f->forks[0] = 1;
			f->forks[index - 1] = index;
			// pthread_mutex_unlock(&f->mu);
			pthread_mutex_unlock(&f->mutex[0]);
			pthread_mutex_unlock(&f->mutex[index - 1]);
		// }
		// printf("\n");
		// int s = 0;
		// while (f->forks[s])
		// {
		// 	printf("  [%d]  ", f->forks[s]);
		// 	s++;
		// }
		// printf("\n");
		// sleep(2);
	}
	// printf("\n");
	// int s = 0;
	// while (f->forks[s])
	// {
	// 	printf("  [%d]  ", f->forks[s]);
	// 	s++;
	// }
	// printf("\n");
	// pthread_mutex_unlock(&f->mutex);
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
			exit(0);
		gettimeofday(&p->tv, NULL);
		time = p->tv.tv_sec * 1000;
		time += p->tv.tv_usec / 1000;
		usleep(100);
	}
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
