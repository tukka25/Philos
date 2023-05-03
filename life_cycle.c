/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:17:18 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/03 20:15:47 by abdamoha         ###   ########.fr       */
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
		// pthread_mutex_lock(&p->f->die);
		// unlock_when_die(p->f);
		// pthread_mutex_unlock(&p->f->die);
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
