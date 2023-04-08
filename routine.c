/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:24:37 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/08 05:39:25 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_philo *p)
{
	int	i = 0;
	while (i < 100)
	{
		pthread_mutex_lock(&p->mutex);
		p->f++;
		i++;
		pthread_mutex_unlock(&p->mutex);
	}
	return (0);
}

void	*routine2(t_philo *p)
{
	p->f++;
	printf("ya captian\n");
	printf("f = %d\n", p->f);
	return (0);
}
