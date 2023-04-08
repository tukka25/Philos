/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:24:37 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/08 20:40:03 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_philo *p)
{
	while (1)
	{
		pthread_mutex_lock(&p->mutex);
		// usleep(1000000);
		took_fork(p);
		eating(p);
		sleeping(p);
		thinking(p);
		died(p);
		pthread_mutex_unlock(&p->mutex);
		usleep(1000000);
	}
	// return ;
}

// void	*routine2(t_philo *p)
// {
// 	p->f++;
// 	printf("ya captian\n");
// 	// printf("f = %d\n", p->f);
// 	return (0);
// }

void	eating(t_philo *p)
{
	p->j = 0;
	printf("\033[0;32m[%d] is eating\n", p->j);
}

void	sleeping(t_philo *p)
{
	p->j = 0;
	printf("\033[0;36m[%d] is sleeping\n", p->j);
}

void	thinking(t_philo *p)
{
	p->j = 0;
	printf("\033[0;35m[%d] is thinking\n", p->j);
}

void	took_fork(t_philo *p)
{
	p->j = 0;
	printf("\033[0;34m[%d] has taken the fork\n", p->j);
}

void	died(t_philo *p)
{
	p->j = 0;
	printf("\033[0;31m[%d] died\n", p->j);
}
