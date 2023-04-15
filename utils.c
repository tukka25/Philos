/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:33:49 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/15 02:23:31 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ph_atoi(char *str, t_philo *p)
{
	int					sign;
	unsigned long long	result;

	result = 0;
	p->j = 0;
	sign = 1;
	while ((str[p->j] >= 9 && str[p->j] <= 13) || (str[p->j] == ' '))
		p->j++;
	if (str[p->j] == '-')
		return (-1);
	ignore_zero(str, p);
	while (str[p->j] >= '0' && str[p->j] <= '9')
	{
		result = result * 10 + str[p->j++] - '0';
		if (((result > INT_MAX && sign == 1)
				|| (result > 2147483648 && sign == -1)))
			return (-1);
	}
	if ((str[p->j] >= ' ' && str[p->j] <= '/')
		|| (str[p->j] >= ':' && str[p->j] < 127)
		|| !ft_isascii(str[p->j]))
		return (-1);
	return (result * sign);
}

int	ft_isdigit_ph(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9')
			|| (str[i] != '+' && (!(str[i] >= '0' && str[i] <= '9'))))
		{
			printf("str = %c\n", str[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}

void	ignore_zero(char *str, t_philo *p)
{
	if ((str[p->j] == '+' || str[p->j] == '-') && str[p->j + 1] != '\0')
		++p->j;
	while (str[p->j] == '0')
		p->j++;
}

int	check_if_died(t_thread *p)
{
	int		i;

	i = 0;
	while (p->f->status[i])
	{
		if (p->f->status[i] == -1)
			return (1);
		i++;
	}
	return (0);
}
