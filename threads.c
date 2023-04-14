/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:25:50 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/15 00:16:33 by abdamoha         ###   ########.fr       */
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
	// memset(p->threads, 0, (p->philos_num + 1) * sizeof(t_thread));
	init_forks(f, p->philos_num);
	thread_init(p, f);
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
		// usleep(100);
		p->in++;
	}
		// p->in--;
}
