/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:25:50 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/26 16:40:11 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	creating_threads(t_philo *p, t_forks *f)
{
	p->in = 0;
	p->t = malloc(p->philos_num * sizeof(pthread_t));
	p->threads = malloc(p->philos_num * sizeof(t_thread));
	f->mutex = malloc(p->philos_num * sizeof(pthread_mutex_t));
	pthread_mutex_init(&f->mu, NULL);
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
	return (0);
}

int	check_dying(t_philo *p)
{
	int			i;
	long long	t;

	i = 0;
	while (1)
	{
		t = ft_gettime();
		if (t - p->threads[i].last_eating >= p->die_t)
		{
			died(&p->threads[i], p->threads[i].index, p->threads->f->current);
			return (1);
		}
		i++;
		if (i == p->philos_num)
			i = 0;
	}
}
