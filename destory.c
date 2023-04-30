/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:07:46 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/30 23:52:22 by abdamoha         ###   ########.fr       */
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
