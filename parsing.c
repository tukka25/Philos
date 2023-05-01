/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:29:03 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/01 22:15:12 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_args(char *argv, t_philo *p)
{
	int		n;

	n = 0;
	if (argv[0] == '\0')
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	n = ph_atoi(argv, p);
	if (n == -1)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (n);
}

int	pars(t_philo *p, char *argv[])
{
	int	n;

	n = 0;
	p->i = 1;
	init(p);
	while (argv[p->i])
	{
		n = init_args(argv[p->i], p);
		if (n < 0)
			return (-1);
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
