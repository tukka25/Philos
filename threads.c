/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:25:50 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/17 21:32:59 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creating_threads(t_philo *p, t_forks *f)
{
	// int	s = 0;
	p->in = 0;
	p->t = malloc(p->philos_num * sizeof(pthread_t));
	// printf("p->philos_num = %d\n", p->philos_num);
	p->threads = malloc(p->philos_num * sizeof(t_thread));
	f->mutex = malloc(p->philos_num * sizeof(pthread_mutex_t));
	pthread_mutex_init(&f->mu, NULL);
	// memset(p->threads, 0, (p->philos_num + 1) * sizeof(t_thread));
	init_forks(f, p->philos_num);
	thread_init(p, f);
	// init_mutexs()
	if (p->philos_num == 1)
	{
		died(&p->threads[0], 1, 0);
		exit(0);
	}
	// while (f->forks[s])
	// {
	// 	printf("  %d  ", f->forks[s]);
	// 	s++;
	// }
	// printf("\n");
	while (p->in < p->philos_num)
	{
		// printf("p = %d\n", p->in);
		pthread_create(&p->t[p->in], NULL, &routine, &p->threads[p->in]);
		// check_dying(p);
		// {
		// 	// died(p, p->index, p->k);
		// 	exit(0);
		// }
		// usleep(100);
		p->in++;
	}
	pthread_mutex_destroy(&f->mu);
		// p->in--;
}

int	check_dying(t_philo *p)
{
	int		i;

	i = 0;
	while (1)
	{
		// printf("k = %d, l = %d\n", p->threads->k, )
		if (p->threads->k - p->threads[i].last_eating >= p->die_t)
		{
			died(&p->threads[i], p->threads[i].index, p->threads->k);
			exit(0);
		}
		if (i == p->philos_num)
			i = 0;
	}
}
