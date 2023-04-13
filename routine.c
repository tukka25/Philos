/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:24:37 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/13 21:50:53 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *t)
{
	t_philo *p = (t_philo *)t;
	// int i = p->index;
	long long k = 0;
	int	j = 0;
	while (1)
	{
		gettimeofday(&p->tv, NULL);
		k = p->tv.tv_sec * 1000;
		k += p->tv.tv_usec / 1000;
		// pthread_mutex_lock(&p->mutex);
		// printf("t = %d\n", p->in);
		// printf("hi\n");
		// printf("")
		if (check_for_forks(p, p->threads[p->in].index) == 1)
		{
			// printf("here\n");
			taking_forks(p, p->threads[p->in].index);
			if (k - p->time >= p->threads[p->in].d_t)
			{
				// printf("died = %lld\n", k - p->time);
				died(&p->threads[p->in], p->threads[p->in].index, k);
				exit(0);
			}
			took_fork(&p->threads[p->in], p->threads[p->in].index, k);
			eating(&p->threads[p->in], p->threads[p->in].index, k);
			// p->d_t = p->die_t;
			return_forks(p, p->threads[p->in].index);
			sleeping(&p->threads[p->in], p->threads[p->in].index, k);
			// printf("\033[0;37m[%d] time to die\033[0m\n", p->d_t);
			thinking(&p->threads[p->in], p->threads[p->in].index, k);
			if (k - p->time >= p->threads[p->in].d_t)
			{
				died(&p->threads[p->in], p->threads[p->in].index, k);
				exit(0);
			}
			// pthread_mutex_unlock(&p->mutex);
			// p->forks[i] = i + 1;
		}
		if (k - p->time >= p->threads[p->in].d_t)
		{
			died(&p->threads[p->in], p->threads[p->in].index, k);
			exit(0);
		}
		// i++;
		// if (i == p->philos_num)
		// 	i = 0;
		j++;
		// sleep(1);
	}
	return (0);
}

// void	*routine2(t_philo *p)
// {
// 	p->f++;
// 	printf("ya captian\n");
// 	// printf("f = %d\n", p->f);
// 	return (0);
// }

void	eating(t_thread *p, int index, long long time)
{
	// (void)p;
	printf("\033[0;32m[%lld] %d is eating\n", time - p->start_t, index);
}

void	sleeping(t_thread *p, int index, long long time)
{
	// (void)p;
	usleep(p->sl_t * 1000);
	printf("\033[0;36m[%lld] %d is sleeping\n", time - p->start_t, index);
}

void	thinking(t_thread *p, int index, long long time)
{
	// (void)p;
	printf("\033[0;35m[%lld] %d is thinking\n", time - p->start_t, index);
}

void	took_fork(t_thread *p, int index, long long time)
{
	int		i;
	int		d;

	i = 0;
	d = 0;
	(void)p;
	// if (d > 0)
	printf("\033[0;34m[%lld] %d has taken the fork\n", time - p->start_t, index);
}

void	died(t_thread *p, int index, long long time)
{
	(void)p;
	printf("\033[0;31m[%lld] %d died\n", time - p->start_t, index);
}
