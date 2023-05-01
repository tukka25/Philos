/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:35:07 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/01 21:09:45 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_philo *p)
{
	int		i;

	i = 0;
	while (i < p->philos_num)
	{
		if (i == 0)
			check_dying(p);
		pthread_join(p->t[i], NULL);
		i++;
	}
}

int	everytime_check(t_forks *f)
{
	int		i;

	i = 0;
	pthread_mutex_lock(&f->e);
	while (f->status[i])
	{
		// pthread_mutex_unlock(&f->e);
		// pthread_mutex_lock(&f->e); 
		if (f->status[i] == -1)
		{
			pthread_mutex_unlock(&f->e);
			// unlock_when_die()
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&f->e);
	return (0);
}

void	unlock_when_die(t_forks *f)
{
	int		i;

	i = 0;
	// pthread_mutex_lock(&f->mu);
	while (f->forks[i])
	{
		// pthread_mutex_unlock(&f->die);
		if (f->forks[i] == -1)
		{
			pthread_mutex_unlock(&f->mutex[i]);
		}
		i++;
	}
	// pthread_mutex_unlock(&f->mu);
	// pthread_mutex_unlock(&f->die);
	// printf("i = %d\n", i);
	// printf("h  %d\n", f->forks[i]);
	// if (f->forks[i + 1] != '\0')
	// {
	// 	pthread_mutex_unlock(&f->mutex[i]);
	// 	pthread_mutex_unlock(&f->mutex[i + 1]);
	// 	// pthread_mutex_unlock(&f->mutex[2]);
	// }
	// else
	// {
	// 	// printf("here\n");
	// 	pthread_mutex_unlock(&f->mutex[0]);
	// 	pthread_mutex_unlock(&f->mutex[i]);
	// 	// pthread_mutex_unlock(&f->mutex[2]);
	// }
	// pthread_mutex_unlock(&f->mu);
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

// int	check_fork_l(t_forks *f, int index)
// {
// 	int		i;

// 	i = 0;
// 	// pthread_mutex_lock(&f->e);
// 	if (f->forks[index] != -1 && f->forks[index - 1] != -1)
// 	{
// 		i = 1;
// 	}
// 	// pthread_mutex_unlock(&f->e);
// 	return (i);
// }
