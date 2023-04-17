/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:29:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/17 21:55:11 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks(t_forks *f, int index)
{
	int	i;
	// int	s = 0;

	i = 0;
	// while (f->forks[i])
	// {
		// pthread_mutex_lock(&f->mutex);
		if (f->forks[index] != '\0')
		{
			// if (f->forks[index + 1] != -1)
			// {
				// printf("1 f1 = %d, f2 = %d\n", f->forks[index - 1], f->forks[index]);
				// if (f->forks[index - 1] == -1 || f->forks[index] == -1)
				// pthread_mutex_lock(&f->mu);
				f->forks[index - 1] = -1;
				f->forks[index] = -1;
				// pthread_mutex_lock(&f->mutex[index - 1]);
				// pthread_mutex_lock(&f->mutex[index]);
				// printf("1 f1 = %d, f2 = %d\n", f->forks[index - 1], f->forks[index]);
				// printf("index = %d\n", index);
				// break ;
			// }
		}
		else
		{
			// printf("2 f1 = %d, f2 = %d\n", f->forks[0], f->forks[index - 1]);
			// if (f->forks[0] == -1 || f->forks[index - 1] = -1)
			// pthread_mutex_lock(&f->mu);
			f->forks[0] = -1;
			f->forks[index - 1] = -1;
			// pthread_mutex_lock(&f->mutex[0]);
			// pthread_mutex_lock(&f->mutex[index - 1]);
			// printf("2 f1 = %d, f2 = %d\n", f->forks[0], f->forks[index - 1]);
			// break ;
		}
		i++;
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
			// pthread_mutex_unlock(&f->mutex[index - 1]);
			// pthread_mutex_unlock(&f->mutex[index]);
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
			// pthread_mutex_unlock(&f->mutex[0]);
			// pthread_mutex_unlock(&f->mutex[index - 1]);
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
		// if (p->k - p->last_eating >= p->d_t)
		// {
		// 	died(p, p->index, p->k);
		// 	exit(0);
		// }
		gettimeofday(&p->tv, NULL);
		time = p->tv.tv_sec * 1000;
		time += p->tv.tv_usec / 1000;
	}
}
