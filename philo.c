/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:21:14 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/08 06:02:38 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *argv[])
{
	t_philo		p;
	// pthread_t	th[4];

	pthread_mutex_init(&p.mutex, NULL);
	p.f = 0;
	if (ac >= 5 && ac <= 6)
	{
		printf("welcome to the shit\n");
		if (pars(&p, argv) < 0)
			return (1);
		threads_create(&p);
		printf("f = %d\n", p.f);
	}
	else
		write(2, "Invalid Arguments\n", 18);
	pthread_mutex_destroy(&p.mutex);
}

void	threads_create(t_philo *p)
{
	int		i;

	i = 0;
	p->t = malloc(p->philos_num * sizeof(pthread_t));
	printf("p->philos_num = %d\n", p->philos_num);
	p->threads = malloc(p->philos_num * sizeof(t_thread));
	while (i < p->philos_num)
	{
		pthread_create(&p->t[i], NULL, &routine, p);
		printf("[%d] started exection\n", i);
		thread_init(p, i);
		i++;
	}
	i = 0;
	while (i < p->philos_num)
	{
		pthread_join(p->t[i], NULL);
		printf("[%d] finished exection\n", i);
		i++;
	}
}

void	thread_init(t_philo *p, int i)
{
	p->threads[i].p_n = p->philos_num;
	p->threads[i].d_t = p->die_t;
	p->threads[i].sl_t = p->sleep_t;
	p->threads[i].e_t = p->eat_t;
	p->threads[i].meals_n = p->meals;
	printf("p = %d\n", p->threads[i].p_n);
	printf("p = %d\n", p->threads[i].d_t);
	printf("p = %d\n", p->threads[i].sl_t);
	printf("p = %d\n", p->threads[i].e_t);
	printf("p = %d\n", p->threads[i].meals_n);
	printf("\n");
}
