/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:21:14 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/08 20:37:13 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arr[10] = {2, 3, 5, 7 ,11, 13, 17, 19, 23, 27};
int	main(int ac, char *argv[])
{
	t_philo		p;

	pthread_mutex_init(&p.mutex, NULL);
	p.f = 0;
	if (ac >= 5 && ac <= 6)
	{
		printf("welcome to the shit\n");
		if (pars(&p, argv) < 0)
			return (1);
		threads_create(&p);
		// printf("f = %d\n", p.f);
	}
	else
		write(2, "Invalid Arguments\n", 18);
	pthread_mutex_destroy(&p.mutex);
}

void	threads_create(t_philo *p)
{
	int		i;

	i = 0;
	init_forks(p);
	creating_threads(p);
	while (i < p->philos_num)
	{
		pthread_join(p->t[i], NULL);
		i++;
	}
}

void	thread_init(t_philo *p, int i)
{
	p->threads[i].index = i;
	p->threads[i].p_n = p->philos_num;
	p->threads[i].d_t = p->die_t;
	p->threads[i].sl_t = p->sleep_t;
	p->threads[i].e_t = p->eat_t;
	p->threads[i].meals_n = p->meals;
}

void	init_forks(t_philo *p)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	p->forks = malloc((p->philos_num + 1) * sizeof(int));
	if (!p->forks)
		return ;
	while (i < p->philos_num)
	{
		p->forks[i] = j;
		i++;
		j++;
	}
	p->forks[i] = 0;
	i = 0;
	while (p->forks[i])
	{
		printf("%d  ", p->forks[i]);
		i++;
	}
}
