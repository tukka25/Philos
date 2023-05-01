/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:07:46 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/01 22:12:12 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_threads(t_philo *p)
{
	free(p->threads);
	free(p->t);
}

void	destroy_everything(t_philo *p)
{
	int		i;

	i = 0;
	while (i < p->philos_num)
	{
		pthread_mutex_destroy(&p->threads->f->mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&p->threads->f->mu);
	pthread_mutex_destroy(&p->threads->f->pri);
	pthread_mutex_destroy(&p->threads->f->die);
	pthread_mutex_destroy(&p->threads->f->e);
	pthread_mutex_destroy(&p->threads->f->every_t);
	pthread_mutex_destroy(&p->threads->f->checker);
	pthread_mutex_destroy(&p->threads->f->loop_d);
	pthread_mutex_destroy(&p->threads->f->fork);
	pthread_mutex_destroy(&p->threads->f->last_e);
	free(p->threads->f->forks);
	free(p->threads->f->status);
	free(p->threads->f->mutex);
	free_threads(p);
}

void	init_status(t_forks *f, int philos_num)
{
	int	i;

	i = 0;
	f->status = malloc((philos_num + 1) * sizeof(int));
	if (!f->status)
		return ;
	while (i < philos_num)
	{
		f->status[i] = 1;
		i++;
	}
	f->status[i] = '\0';
}

void	died(t_thread *p, int index, long long time)
{
	long long	b;

	(void)time;
	b = ft_gettime();
	pthread_mutex_lock(&p->f->loop_d);
	if (p->i != p->meals_n)
	{
		pthread_mutex_lock(&p->f->pri);
		printf("\033[0;31m %lld %d died\n", b - p->start_t, index);
		pthread_mutex_unlock(&p->f->pri);
	}
	pthread_mutex_unlock(&p->f->loop_d);
}

void	init_mutexs(t_forks *f)
{
	pthread_mutex_init(&f->fork, NULL);
	pthread_mutex_init(&f->mu, NULL);
	pthread_mutex_init(&f->pri, NULL);
	pthread_mutex_init(&f->die, NULL);
	pthread_mutex_init(&f->e, NULL);
	pthread_mutex_init(&f->every_t, NULL);
	pthread_mutex_init(&f->checker, NULL);
	pthread_mutex_init(&f->loop_d, NULL);
	pthread_mutex_init(&f->last_e, NULL);
}
