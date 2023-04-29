/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:35:07 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/29 19:00:23 by abdamoha         ###   ########.fr       */
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

void	unlock_when_die(t_forks *f)
{
	int		i;

	i = 0;
	// while (f->forks[i])
	// {
	// 	printf("  %d", f->forks[i]);
	// 	i++;
	// }
	// printf("\n");
	i = 0;
	while (f->forks[i])
	{
		if (f->forks[i] == -1)
		{
			break ;
		}
		i++;
	}
	// printf("i = %d\n", i);
	// printf("h  %d\n", f->forks[i]);
	if (f->forks[i + 1] != '\0')
	{
		pthread_mutex_unlock(&f->mutex[0]);
		pthread_mutex_unlock(&f->mutex[1]);
		pthread_mutex_unlock(&f->mutex[2]);
	}
	else
	{
		// printf("here\n");
		pthread_mutex_unlock(&f->mutex[0]);
		pthread_mutex_unlock(&f->mutex[1]);
		pthread_mutex_unlock(&f->mutex[2]);
	}
}

int	about_to_die(t_thread *p, int index)
{
	long long	t;

	(void)index;
	t = ft_gettime();
	if (t - p->last_eating >= p->d_t % 2)
		return (0);
	return (1);
}
