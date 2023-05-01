/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:25:50 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/01 21:19:59 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	creating_threads(t_philo *p, t_forks *f)
{
	p->in = 0;
	p->t = malloc(p->philos_num * sizeof(pthread_t));
	if (!p->t)
		return (1);
	p->threads = malloc(p->philos_num * sizeof(t_thread));
	if (!p->threads)
		return (1);
	f->mutex = malloc(p->philos_num * sizeof(pthread_mutex_t));
	if (!f->mutex)
		return (1);
	pthread_mutex_init(&f->fork, NULL);
	pthread_mutex_init(&f->mu, NULL);
	pthread_mutex_init(&f->pri, NULL);
	pthread_mutex_init(&f->die, NULL);
	pthread_mutex_init(&f->e, NULL);
	pthread_mutex_init(&f->every_t, NULL);
	pthread_mutex_init(&f->checker, NULL);
	pthread_mutex_init(&f->loop_d, NULL);
	pthread_mutex_init(&f->last_e, NULL);
	init_forks(f, p->philos_num);
	thread_init(p, f);
	if (p->philos_num == 1)
	{
		died(&p->threads[0], 1, 0);
		return (1);
	}
	while (p->in < p->philos_num)
	{
		pthread_create(&p->t[p->in], NULL, &routine, &p->threads[p->in]);
		p->in++;
	}
	join_threads(p);
	return (0);
}

int	check_dying(t_philo *p)
{
	int			i;
	long long	t;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&p->threads->f->last_e);
		t = ft_gettime();
		if (t - p->threads[i].last_eating >= p->die_t)
		{
			pthread_mutex_lock(&p->threads->f->e);
			p->threads[i].f->status[p->threads[i].index - 1] = -1;
			died(&p->threads[i], p->threads[i].index, p->threads->f->current);
			pthread_mutex_unlock(&p->threads->f->e);
			pthread_mutex_unlock(&p->threads->f->last_e);
			return (1);
		}
		pthread_mutex_unlock(&p->threads->f->last_e);
		usleep(50);
		i++;
		if (i == p->philos_num)
			i = 0;
	}
}

// int	forky(t_philo *p, int i)
// {
// 	if (p->threads->f->forks[p->threads[i].index - 1] == -1)
// 	{
// 		return (1);
// 	}
// 	return (0);
// }
