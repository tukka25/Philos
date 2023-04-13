/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:21:14 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/13 04:00:33 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *argv[])
{
	t_philo			p;

	pthread_mutex_init(&p.mutex, NULL);
	p.f = 0;
	if (ac >= 5 && ac <= 6)
	{
		printf("welcome to the shit\n");
		if (pars(&p, argv) < 0)
			return (1);
		gettimeofday(&p.tv, NULL);
		p.time = p.tv.tv_sec * 1000;
		p.time += p.tv.tv_usec / 1000;
		// printf("t = %d\n", p.tv.tv_usec);
		threads_create(&p);
	}
	else
		write(2, "Invalid Arguments\n", 18);
	pthread_mutex_destroy(&p.mutex);
}

void	threads_create(t_philo *p)
{
	int		i;

	i = 0;
	creating_threads(p);
	while (i < p->philos_num)
	{
		pthread_join(p->t[i], NULL);
		i++;
	}
}

void	thread_init(t_philo *p)
{
	int	i;

	i = 0;
	while (i < p->philos_num)
	{
		p->threads[i].index = i + 1;
		p->threads[i].p_n = p->philos_num;
		p->threads[i].d_t = p->die_t;
		p->threads[i].sl_t = p->sleep_t;
		p->threads[i].e_t = p->eat_t;
		p->threads[i].meals_n = p->meals;
		p->threads[i].start_t = p->time;
		// printf("index = %d\n", p->threads[i].index);
		i++;
	}
}

void	init_forks(t_philo *p, int philos_num)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	p->forks = malloc((philos_num + 1) * sizeof(int));
	if (!p->forks)
		return ;
	while (i < philos_num)
	{
		p->forks[i] = j;
		i++;
		j++;
	}
	p->forks[i] = '\0';
}
