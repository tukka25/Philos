/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:17:18 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/04 19:24:34 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine2(t_thread *p)
{
	eating(p, p->index, 0);
	pthread_mutex_lock(&p->f->loop_d);
	p->i++;
	pthread_mutex_unlock(&p->f->loop_d);
	sleeping(p, p->index, 0);
	thinking(p, p->index, 0);
}

int	inside_checker(t_thread *p)
{
	if (took_fork(p, p->index, 0) == 1)
	{
		unlock_when_die(p);
		pthread_mutex_lock(&p->f->e);
		p->f->status[p->index - 1] = -1;
		pthread_mutex_unlock(&p->f->e);
		pthread_mutex_unlock(&p->f->mu);
		return (0);
	}
	return (1);
}

int	status_checker(t_thread *p)
{
	pthread_mutex_lock(&p->f->every_t);
	if (everytime_check(p->f) == 1)
	{
		pthread_mutex_unlock(&p->f->every_t);
		return (0);
	}
	pthread_mutex_unlock(&p->f->every_t);
	return (1);
}

void	greedy_shit(t_thread *p)
{
	pthread_mutex_lock(&p->f->checker);
	if (p->f->arr[p->index] != '\0')
	{
		p->f->arr[p->index - 1] = p->index;
		p->f->arr[p->index] = p->index;
	}
	else
	{
		p->f->arr[0] = p->index;
		p->f->arr[p->index - 1] = p->index;
	}
	pthread_mutex_unlock(&p->f->checker);
}

int	greedy_shit_checker(t_thread *p)
{
	pthread_mutex_lock(&p->f->checker);
	if (p->f->arr[p->index] != '\0')
	{
		if (p->f->arr[p->index - 1] == p->index
			&& p->f->arr[p->index] == p->index)
		{
			pthread_mutex_unlock(&p->f->checker);
			return (1);
		}
	}
	else
	{
		if (p->f->arr[0] == p->index
			&& p->f->arr[p->index - 1] == p->index)
		{
			pthread_mutex_unlock(&p->f->checker);
			return (1);
		}
	}
	pthread_mutex_unlock(&p->f->checker);
	return (0);
}
