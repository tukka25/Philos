/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:29:03 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/08 06:01:59 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	priniting(t_philo *p)
{
	printf("philo num = %d\n", p->philos_num);
	printf("philo num = %d\n", p->die_t);
	printf("philo num = %d\n", p->eat_t);
	printf("philo num = %d\n", p->sleep_t);
	printf("philo num = %d\n", p->meals);
	printf("all right\n");
}

int	pars(t_philo *p, char *argv[])
{
	int	n;

	n = 0;
	p->i = 1;
	init(p);
	while (argv[p->i])
	{
		n = ph_atoi(argv[p->i], p);
		if (n == -1)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		if (p->i == 1 && n)
			p->philos_num = n;
		if (p->i == 2 && n)
			p->die_t = n;
		if (p->i == 3 && n)
			p->eat_t = n;
		if (p->i == 4 && n)
			p->sleep_t = n;
		if (p->i == 5 && n)
			p->meals = n;
		p->i++;
	}
	priniting(p);
	return (0);
}

void	init(t_philo *p)
{
	p->philos_num = 0;
	p->die_t = 0;
	p->eat_t = 0;
	p->sleep_t = 0;
	p->meals = 0;
}
