/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:25:50 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/08 20:39:45 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creating_threads(t_philo *p)
{
	int		i;

	i = 0;
	p->t = malloc(p->philos_num * sizeof(pthread_t));
	printf("p->philos_num = %d\n", p->philos_num);
	p->threads = malloc(p->philos_num * sizeof(t_thread));
	while (i < p->philos_num)
	{
		thread_init(p, i);
		pthread_create(&p->t[i], NULL, &routine, p);
		i++;
	}
}
