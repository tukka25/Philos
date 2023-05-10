/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:21:14 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/06 17:28:39 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *argv[])
{
	t_philo			p;
	t_forks			f;

	p.f = 0;
	p.in = 0;
	if (ac >= 5 && ac <= 6)
	{
		if (pars(&p, argv) < 0)
			return (1);
		gettimeofday(&p.tv, NULL);
		p.time = p.tv.tv_sec * 1000;
		p.time += p.tv.tv_usec / 1000;
		if (threads_create(&p, &f) == 1)
			destroy_everything(&p);
	}
	else
		write(2, "Invalid Arguments\n", 18);
}

int	threads_create(t_philo *p, t_forks *f)
{
	if (p->philos_num > 0)
		if (creating_threads(p, f) == 1)
			return (1);
	return (0);
}

static void	setting_values(t_philo *p, t_forks *f, int i)
{
	p->threads[i].start_t = p->time;
	p->threads[i].f = f;
	p->threads[i].f->forks = f->forks;
	p->threads[i].f->status = f->status;
	p->threads[i].f->mutex = f->mutex;
	p->threads[i].last_eating = p->time;
	p->threads[i].f->current = p->time;
	p->threads[i].f->bye = f->bye;
	p->threads[i].died = 0;
}

void	thread_init(t_philo *p, t_forks *f)
{
	int	i;

	i = -1;
	f->current = p->time;
	f->bye = 0;
	while (++i < p->philos_num)
		pthread_mutex_init(&f->mutex[i], NULL);
	i = 0;
	while (i < p->philos_num)
	{
		p->threads[i].i = 0;
		p->threads[i].index = i + 1;
		p->threads[i].p_n = p->philos_num;
		p->threads[i].d_t = p->die_t;
		p->threads[i].sl_t = p->sleep_t;
		p->threads[i].e_t = p->eat_t;
		if (p->meals == 0)
			p->threads[i].meals_n = 0;
		p->threads[i].meals_n = p->meals;
		setting_values(p, f, i);
		i++;
	}
}

void	init_forks(t_forks *f, int philos_num)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	f->forks = malloc((philos_num + 1) * sizeof(int));
	if (!f->forks)
		return ;
	f->arr = malloc((philos_num + 1) * sizeof(int));
	if (!f->arr)
		return ;
	if (!f->forks)
		return ;
	while (i < philos_num)
	{
		f->forks[i] = j;
		f->arr[i] = j;
		i++;
		j++;
	}
	f->forks[i] = '\0';
	f->arr[i] = '\0';
	init_status(f, philos_num);
}
