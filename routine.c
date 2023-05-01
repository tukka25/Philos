/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:24:37 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/01 20:02:27 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *t)
{
	t_thread	*p = (t_thread *)t;
	while (p->i < p->meals_n)
	{
		// if (everytime_check(p->f) == 1)
		// 	return (0);
		// pthread_mutex_lock(&p->f->mu);
		// p->f->current = ft_gettime();
		// pthread_mutex_unlock(&p->f->mu);
		pthread_mutex_lock(&p->f->every_t);
		if (everytime_check(p->f) == 1)
		{
			// pthread_mutex_unlock(&p->f->loop_d);
			// unlock_when_die(p->f);
			pthread_mutex_unlock(&p->f->every_t);
			return (0);
		}
		pthread_mutex_unlock(&p->f->every_t);
		if (check_for_forks(p->f, p->index) == 1)
		{
			// printf("index ");
			pthread_mutex_lock(&p->f->every_t);
			if (everytime_check(p->f) == 1)
			{
				// unlock_when_die(p->f);
				pthread_mutex_unlock(&p->f->every_t);
				return (0);
			}
			pthread_mutex_unlock(&p->f->every_t);
				taking_forks(p->f, p->index);
				pthread_mutex_lock(&p->f->mu);
				if (took_fork(p, p->index, 0) == 1)
				{
					// return_forks(p->f, p->index);
					pthread_mutex_lock(&p->f->die);
					unlock_when_die(p->f);
					pthread_mutex_unlock(&p->f->die);
					pthread_mutex_lock(&p->f->e);
					p->f->status[p->index - 1] = -1;
					pthread_mutex_unlock(&p->f->e);
					pthread_mutex_unlock(&p->f->mu);
					return (0);
				}
				pthread_mutex_unlock(&p->f->mu);
				eating(p, p->index, 0);
				p->i++;
				// if (everytime_check(p->f) == 1)
				// 	return (0);
				sleeping(p, p->index, 0);
				thinking(p, p->index, 0);
			// }
			// if (everytime_check(p->f) == 1)
			// 	return (0);
		}
		// pthread_mutex_lock(&p->f->loop_d);
		// pthread_mutex_unlock(&p->f->loop_d);
		// pthread_mutex_unlock(&p->f->mutex);
		// if (0 - p->last_eating >= p->d_t)
		// {
		// 	died(p, p->index, 0);
		// 	exit(0);
		// }
		// if (check_if_died(p) == 1)
		// 	return (0);
		// j++;
		// sleep(1);
	}
	// if (everytime_check(p->f) == 1)
	// 	return (0);
	return (0);
}

void	eating(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	b = ft_gettime();
	pthread_mutex_lock(&p->f->last_e);
	p->last_eating = b;
	pthread_mutex_unlock(&p->f->last_e);
	pthread_mutex_lock(&p->f->every_t);
	if (everytime_check(p->f) == 1)
	{
		// unlock_when_die(p->f);
		pthread_mutex_unlock(&p->f->every_t);
		return ;
	}
	pthread_mutex_unlock(&p->f->every_t);
	pthread_mutex_lock(&p->f->pri);
	printf("\033[0;32m %lld %d is eating\n", b - p->start_t, index);
	pthread_mutex_unlock(&p->f->pri);
	ft_usleep(p, p->e_t);
	pthread_mutex_lock(&p->f->fork);
	return_forks(p->f, p->index);
	pthread_mutex_unlock(&p->f->fork);
	gettimeofday(&p->tv, NULL);
}

void	sleeping(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	b = ft_gettime();
	pthread_mutex_lock(&p->f->every_t);
	if (everytime_check(p->f) == 1)
	{
		// unlock_when_die(p->f);
		pthread_mutex_unlock(&p->f->every_t);
		return ;
	}
	pthread_mutex_unlock(&p->f->every_t);
	pthread_mutex_lock(&p->f->pri);
	printf("\033[0;36m %lld %d is sleeping\n", b - p->start_t, index);
	pthread_mutex_unlock(&p->f->pri);
	ft_usleep(p, p->sl_t);
	b = ft_gettime();
	if (everytime_check(p->f) == 1)
	{
		unlock_when_die(p->f);
		return ;
	}
	// pthread_mutex_unlock(&p->f->pri);
}

void	thinking(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	b = ft_gettime();
	pthread_mutex_lock(&p->f->every_t);
	if (everytime_check(p->f) == 1)
	{
		// unlock_when_die(p->f);
		pthread_mutex_unlock(&p->f->every_t);
		return ;
	}
	pthread_mutex_unlock(&p->f->every_t);
	ft_usleep(p, 2);
	pthread_mutex_lock(&p->f->every_t);
	if (everytime_check(p->f) == 1)
	{
		// unlock_when_die(p->f);
		pthread_mutex_unlock(&p->f->every_t);
		return ;
	}
	pthread_mutex_unlock(&p->f->every_t);
	pthread_mutex_lock(&p->f->pri);
	printf("\033[0;35m %lld %d is thinking\n", b - p->start_t, index);
	pthread_mutex_unlock(&p->f->pri);
	// usleep(100);
}

int	took_fork(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	b = ft_gettime();
	if (everytime_check(p->f) == 1)
	{
		// unlock_when_die(p->f);
		return (0);
	}
	pthread_mutex_lock(&p->f->pri);
	printf("\033[0;34m %lld %d has taken the fork\n", b - p->start_t, index);
	pthread_mutex_unlock(&p->f->pri);
	if (check_if_died(p) == 1)
	{
		p->died = 1;
		// unlock_when_die(p->f);
		// died(p, p->index, p->f->current);
		return (1);
	}
	return (0);
}

void	died(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	b = ft_gettime();
	pthread_mutex_lock(&p->f->pri);
	printf("\033[0;31m %lld %d died\n", b - p->start_t, index);
	pthread_mutex_unlock(&p->f->pri);
	// gettimeofday(&p->tv, NULL);
	// p->f->current = p->tv.tv_sec * 1000;
	// p->f->current += p->tv.tv_usec / 1000;
	// pthread_mutex_lock(&p->f->mu);
	// p->f->status[index] = -1;
	// pthread_mutex_unlock(&p->f->mu);
}
