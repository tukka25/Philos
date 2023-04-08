/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:20:06 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/08 20:36:13 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_thread
{
	int				index;
	int				p_n;
	int				d_t;
	int				e_t;
	int				sl_t;
	int				meals_n;
}	t_thread;

typedef struct s_philo
{
	int				i;
	int				j;
	int				f;
	int				philos_num;
	int				die_t;
	int				eat_t;
	int				sleep_t;
	int				meals;
	pthread_t		*t;
	t_thread		*threads;
	int				*forks;
	int				arr[9];
	pthread_mutex_t	mutex;
}	t_philo;


int		pars(t_philo *p, char *argv[]);
long	ph_atoi(char *str, t_philo *p);
int		ft_isdigit_ph(char *str);
void	exit_message(void);
int		ft_isascii(int c);
void	ignore_zero(char *str, t_philo *p);
void	*routine();
void	*routine2();
void	threads_create(t_philo *p);
void	thread_init(t_philo *p, int i);
void	init(t_philo *p);
void	init_forks(t_philo *p);
void	creating_threads(t_philo *p);
void	eating(t_philo *p);
void	sleeping(t_philo *p);
void	died(t_philo *p);
void	thinking(t_philo *p);
void	took_fork(t_philo *p);
#endif