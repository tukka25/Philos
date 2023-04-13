/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:25:50 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/13 21:54:44 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creating_threads(t_philo *p)
{
	p->in = 0;
	p->t = malloc(p->philos_num * sizeof(pthread_t));
	printf("p->philos_num = %d\n", p->philos_num);
	p->threads = malloc(p->philos_num * sizeof(t_thread));
	// memset(p->threads, 0, (p->philos_num + 1) * sizeof(t_thread));
	thread_init(p);
	init_forks(p, p->philos_num);
	while (p->in < p->philos_num)
	{
		// printf("p = %d\n", p->in);
		pthread_create(&p->t[p->in], NULL, &routine, p);
		// usleep(100);
		p->in++;
	}
		// p->in--;
}
