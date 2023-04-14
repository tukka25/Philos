/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:29:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/14 23:19:32 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks(t_forks *f, int index)
{
	int	i;
	// int	s = 0;

	i = 0;
	// while (f->forks[i])
	// {
		if (f->forks[index])
		{
			// if (f->forks[index + 1] != -1)
			// {
				f->forks[index - 1] = -1;
				f->forks[index] = -1;
				// break ;
			// }
		}
		else
		{
			// printf("hihi\n");
			f->forks[0] = -1;
			f->forks[index - 1] = -1;
			// break ;
		}
		i++;
	// }
	// printf("\n");
	// while (f->forks[s])
	// {
	// 	printf("  {%d}  ", f->forks[s]);
	// 	s++;
	// }
	// printf("\n");
}

int	check_for_forks(t_forks *f, int index)
{
	// printf("index = %d\n", index);
	// printf("fork = %d", f->forks[index]);
	if (f->forks[index] != '\0')
	{
		if (f->forks[index - 1] != -1 && f->forks[index] != -1)
			return (1);
		return (0);
	}
	else
	{
		if (f->forks[0] != -1)
			return (1);
	}
	return (0);
}

void	return_forks(t_forks *f, int index)
{
	// printf("return index = %d\n", index);
	if (f->forks[index] != '\0')
	{
		f->forks[index - 1] = index;
		f->forks[index] = index + 1;
	}
	else
	{
		f->forks[0] = 1;
		f->forks[index - 1] = index;
	}
}

void	ft_usleep(t_thread *p, int l)
{
	long long	time;
	long long	time2;

	gettimeofday(&p->tv, NULL);
	time2 = p->tv.tv_sec * 1000;
	time2 += p->tv.tv_usec / 1000;
	time = time2;
	while (time - time2 < l)
	{
		gettimeofday(&p->tv, NULL);
		time = p->tv.tv_sec * 1000;
		time += p->tv.tv_usec / 1000;
	}
}
