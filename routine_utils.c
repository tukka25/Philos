/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:35:07 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/04 19:25:17 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_threads(t_philo *p)
{
	int		i;

	i = 0;
	while (i < p->philos_num)
	{
		if (i == 0)
			check_dying(p);
		pthread_join(p->t[i], NULL);
		i++;
	}
	return (1);
}

int	everytime_check(t_forks *f)
{
	int		i;

	i = 0;
	pthread_mutex_lock(&f->e);
	while (f->status[i])
	{
		if (f->status[i] == -1)
		{
			pthread_mutex_unlock(&f->e);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&f->e);
	return (0);
}

void	unlock_when_die(t_thread *p)
{
	pthread_mutex_lock(&p->f->fork);
	if (p->f->forks[p->index] != '\0')
	{
		if (p->f->forks[p->index - 1] == -1 && p->f->forks[p->index] == -1)
		{
			pthread_mutex_unlock(&p->f->mutex[p->index - 1]);
			pthread_mutex_unlock(&p->f->mutex[p->index]);
			p->f->forks[p->index - 1] = p->index;
			p->f->forks[p->index] = p->index + 1;
		}
	}
	else
	{
		if (p->f->forks[p->index - 1] == -1 && p->f->forks[0] == -1)
		{
			pthread_mutex_unlock(&p->f->mutex[0]);
			pthread_mutex_unlock(&p->f->mutex[p->index - 1]);
			p->f->forks[p->index - 1] = p->index;
			p->f->forks[0] = 1;
		}
	}
	pthread_mutex_unlock(&p->f->fork);
}

void	unlock_inside(t_forks *f, int i)
{
	pthread_mutex_lock(&f->fork);
	if (f->forks[i - 1] == -1)
	{
		pthread_mutex_unlock(&f->mutex[i - 1]);
		f->forks[i - 1] = i + 1;
	}
	if (f->forks[i] == -1)
	{
		pthread_mutex_unlock(&f->mutex[i]);
		f->forks[i] = i + 1;
	}
	pthread_mutex_unlock(&f->fork);
}
