/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:24:37 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/26 17:51:46 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *t)
{
	t_thread	*p = (t_thread *)t;
	while (1)
	{
		p->f->current = ft_gettime();
		if (everytime_check(p->f) == 1)
			return (0);
		if (check_for_forks(p->f, p->index) == 1)
		{
			// printf("index ");
			if (everytime_check(p->f) == 1)
				return (0);
			pthread_mutex_lock(&p->f->mu);
			if (everytime_check(p->f) == 1)
			{
				pthread_mutex_unlock(&p->f->mu);
				return (0);
			}
			taking_forks(p->f, p->index);
			pthread_mutex_unlock(&p->f->mu);
			if (took_fork(p, p->index, p->f->current) == 1)
			{
				return_forks(p->f, p->index);
				p->f->status[p->index - 1] = -1;
				return (0);
			}
			eating(p, p->index, p->f->current);
			if (everytime_check(p->f) == 1)
				return (0);
			sleeping(p, p->index, p->f->current);
			if (everytime_check(p->f) == 1)
				return (0);
			thinking(p, p->index, p->f->current);
			if (everytime_check(p->f) == 1)
			return (0);
			// pthread_mutex_unlock(&p->f->mu);
			// pthread_mutex_unlock(&p->f->mutex);
			// if (p->f->current - p->last_eating > p->d_t)
			// {
			// 	died(p, p->index, p->f->current);
			// 	exit(0);
			// }
			// pthread_mutex_unlock(&p->mutex);
			// p->forks[i] = i + 1;
		}
		// pthread_mutex_unlock(&p->f->mutex);
		// if (p->f->current - p->last_eating >= p->d_t)
		// {
		// 	died(p, p->index, p->f->current);
		// 	exit(0);
		// }
		// if (check_if_died(p) == 1)
		// 	return (0);
		// j++;
		// sleep(1);
	}
	return (0);
}

void	eating(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	b = ft_gettime();
	p->last_eating = p->f->current;
	printf("\033[0;32m[%lld] %d is eating\n", b - p->start_t, index);
	ft_usleep(p, p->e_t);
	return_forks(p->f, p->index);
	gettimeofday(&p->tv, NULL);
	p->f->current = p->tv.tv_sec * 1000;
	p->f->current += p->tv.tv_usec / 1000;
	// pthread_mutex_lock(&p->f->mu);
	if (everytime_check(p->f) == 1)
		return ;
	// pthread_mutex_unlock(&p->f->mu);
}

void	sleeping(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	b = ft_gettime();
	printf("\033[0;36m[%lld] %d is sleeping\n", b - p->start_t, index);
	ft_usleep(p, p->sl_t);
	b = ft_gettime();
	if (everytime_check(p->f) == 1)
		return ;
	// pthread_mutex_unlock(&p->f->mu);
}

void	thinking(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	b = ft_gettime();
	if (everytime_check(p->f) == 1)
		return ;
	printf("\033[0;35m[%lld] %d is thinking\n", b - p->start_t, index);
	// pthread_mutex_unlock(&p->f->mu);
}

int	took_fork(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	b = ft_gettime();
	printf("\033[0;34m[%lld] %d has taken the fork\n", b - p->start_t, index);
	if (check_if_died(p) == 1)
	{
		p->died = 1;
		died(p, p->index, p->f->current);
		return (1);
	}
	if (everytime_check(p->f) == 1)
		return (0);
	return (0);
}

void	died(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	b = ft_gettime();
	printf("\033[0;31m[%lld] %d died\n", b - p->start_t, index);
	// gettimeofday(&p->tv, NULL);
	// p->f->current = p->tv.tv_sec * 1000;
	// p->f->current += p->tv.tv_usec / 1000;
	p->f->status[index] = -1;
	// pthread_mutex_lock(&p->f->mu);
	// pthread_mutex_unlock(&p->f->mu);
}
