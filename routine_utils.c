/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:35:07 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/26 17:38:35 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_philo *p)
{
	int		i;

	i = 0;
	while (i < p->philos_num)
	{
		pthread_join(p->t[i], NULL);
		i++;
	}
}

int	everytime_check(t_forks *f)
{
	int		i;

	i = 0;
	while (f->status[i])
	{
		if (f->status[i] == -1)
			return (1);
		i++;
	}
	return (0);
}
