/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:29:01 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/13 04:03:10 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks(t_philo *p, int index)
{
	int	i;
	int	s = 0;

	i = 0;
	while (p->forks[i])
	{
		if (p->forks[index])
		{
			if (p->forks[index + 1] != -1)
			{
				p->forks[index - 1] = -1;
				p->forks[index] = -1;
				break ;
			}
		}
		else
		{
			// printf("hihi\n");
			p->forks[0] = -1;
			p->forks[index - 1] = -1;
			break ;
		}
		i++;
	}
	while (p->forks[s])
	{
		printf("  {%d}  ", p->forks[s]);
		s++;
	}
	printf("\n");
}

int	check_for_forks(t_philo *p, int index)
{
	// printf("index = %d\n", index);
	// printf("fork = %d", p->forks[index]);
	if (p->forks[index] != '\0')
	{
		if (p->forks[index] != -1 && p->forks[index + 1] != -1)
			return (1);
		return (0);
	}
	else
	{
		if (p->forks[0] != -1)
			return (1);
	}
	return (0);
}

void	return_forks(t_philo *p, int index)
{
	printf("return index = %d\n", index);
	if (p->forks[index] != '\0')
	{
		p->forks[index - 1] = index;
		p->forks[index] = index + 1;
	}
	else
	{
		p->forks[0] = 1;
		p->forks[index - 1] = index;
	}
	int s = 0;
	while (p->forks[s])
	{
		printf("  [%d]  ", p->forks[s]);
		s++;
	}
	printf("\n");
}
