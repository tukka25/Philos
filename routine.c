/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:24:37 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/15 00:19:04 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *t)
{
	t_thread	*p = (t_thread *)t;
	// int i = p->index;
	p->k = 0;
	int	j = 0;
	while (1)
	{
		gettimeofday(&p->tv, NULL);
		p->k = p->tv.tv_sec * 1000;
		p->k += p->tv.tv_usec / 1000;
		// pthread_mutex_lock(&p->mutex);
		// printf("t = %lld\n", p->k);
		// printf("p = %lld\n", p->last_eating);
		// printf("hi\n");
		// printf("")
		// if (check_for_forks(p->f, p->index) == 0)
		// 	pthread_mutex_lock(&p->mutex);
		if (p->k - p->last_eating >= p->d_t)
		{
			died(p, p->index, p->k);
			exit(0);
		}
		if (check_for_forks(p->f, p->index) == 1)
		{
			// printf("here\n");
			// pthread_mutex_lock(&p->f->mutex);
			taking_forks(p->f, p->index);
			// pthread_mutex_unlock(&p->f->mutex);
			// if (k - p->start_t >= p->d_t)
			// {
			// 	// printf("died = %lld\n", p->k - p->start_t);
			// 	died(p, p->index, p->k);
			// 	exit(0);
			// }
			// pthread_mutex_lock(&p->f->mutex);
			took_fork(p, p->index, p->k);
			// pthread_mutex_unlock(&p->f->mutex);
			// pthread_mutex_lock(&p->f->mutex);
			eating(p, p->index, p->k);
			return_forks(p->f, p->index);
			// pthread_mutex_lock(&p->f->mutex);
			sleeping(p, p->index, p->k);
			// pthread_mutex_unlock(&p->f->mutex);
			// printf("\033[0;37m[%d] time to die\033[0m\n", p->d_t);
			// pthread_mutex_lock(&p->f->mutex);
			thinking(p, p->index, p->k);
			// pthread_mutex_unlock(&p->f->mutex);
			if (p->k - p->last_eating > p->d_t)
			{
				died(p, p->index, p->k);
				exit(0);
			}
			// pthread_mutex_unlock(&p->mutex);
			// p->forks[i] = i + 1;
		}
		if (p->k - p->last_eating >= p->d_t)
		{
			died(p, p->index, p->k);
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
	ft_usleep(p, p->e_t);
	gettimeofday(&p->tv, NULL);
	time = p->tv.tv_sec * 1000;
	time += p->tv.tv_usec / 1000;
	p->last_eating = time;
	printf("\033[0;32m[%lld] %d is eating\n", time - p->start_t, index);
}

void	sleeping(t_thread *p, int index, long long time)
{
	ft_usleep(p, p->sl_t);
	gettimeofday(&p->tv, NULL);
	time = p->tv.tv_sec * 1000;
	time += p->tv.tv_usec / 1000;
	printf("\033[0;36m[%lld] %d is sleeping\n", time - p->start_t, index);
}

void	thinking(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	gettimeofday(&p->tv, NULL);
	b = p->tv.tv_sec * 1000;
	b += p->tv.tv_usec / 1000;
	// printf("p = %lld\n", p->start_t);
	// printf("p = %lld\n", b);
	printf("\033[0;35m[%lld] %d is thinking\n", b - p->start_t, index);
}

void	took_fork(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	gettimeofday(&p->tv, NULL);
	b = p->tv.tv_sec * 1000;
	b += p->tv.tv_usec / 1000;
	printf("\033[0;34m[%lld] %d has taken the fork\n", time - p->start_t, index);
}

void	died(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	gettimeofday(&p->tv, NULL);
	b = p->tv.tv_sec * 1000;
	b += p->tv.tv_usec / 1000;
	// printf("p = %lld\n", p->start_t);
	// printf("p = %lld\n", b);
	printf("\033[0;31m[%lld] %d died\n", b - p->start_t, index);
}
