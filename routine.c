/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:24:37 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/04 19:25:07 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *t)
{
	t_thread	*p;

	p = (t_thread *)t;
	while (p->i < p->meals_n)
	{
		if (status_checker(p) == 0)
			return (0);
		if (greedy_shit_checker(p) == 1)
			ft_usleep(p, p->e_t / 2 + p->e_t / 4);
		if (check_for_forks(p->f, p->index) == 1)
		{
			if (status_checker(p) == 0)
				return (0);
			taking_forks(p->f, p->index);
			pthread_mutex_lock(&p->f->mu);
			if (inside_checker(p) == 0)
				return (0);
			pthread_mutex_unlock(&p->f->mu);
			routine2(p);
		}
	}
	unlock_when_die(p);
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
		pthread_mutex_unlock(&p->f->every_t);
		unlock_inside(p->f, p->index);
		return ;
	}
	pthread_mutex_unlock(&p->f->every_t);
	pthread_mutex_lock(&p->f->pri);
	printf("\033[0;32m %lld %d is eating\n", b - p->start_t, index);
	pthread_mutex_unlock(&p->f->pri);
	greedy_shit(p);
	ft_usleep(p, p->e_t);
	return_forks(p->f, p->index);
}

void	sleeping(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	b = ft_gettime();
	pthread_mutex_lock(&p->f->every_t);
	if (everytime_check(p->f) == 1)
	{
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
		return ;
}

void	thinking(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	b = ft_gettime();
	pthread_mutex_lock(&p->f->every_t);
	if (everytime_check(p->f) == 1)
	{
		pthread_mutex_unlock(&p->f->every_t);
		return ;
	}
	pthread_mutex_unlock(&p->f->every_t);
	ft_usleep(p, 2);
	usleep(700);
	pthread_mutex_lock(&p->f->every_t);
	if (everytime_check(p->f) == 1)
	{
		pthread_mutex_unlock(&p->f->every_t);
		return ;
	}
	pthread_mutex_unlock(&p->f->every_t);
	pthread_mutex_lock(&p->f->pri);
	printf("\033[0;35m %lld %d is thinking\n", b - p->start_t, index);
	pthread_mutex_unlock(&p->f->pri);
}

int	took_fork(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	b = ft_gettime();
	if (everytime_check(p->f) == 1)
		return (1);
	pthread_mutex_lock(&p->f->pri);
	if (everytime_check(p->f) == 1)
	{
		pthread_mutex_unlock(&p->f->pri);
		return (1);
	}
	printf("\033[0;34m %lld %d has taken the fork\n", b - p->start_t, index);
	pthread_mutex_unlock(&p->f->pri);
	return (0);
}
