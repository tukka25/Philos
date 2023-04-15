/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:20:06 by abdamoha          #+#    #+#             */
/*   Updated: 2023/04/15 02:24:02 by abdamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_forks
{
	int				*forks;
	pthread_mutex_t	mutex;
	int				*status;
}	t_forks;

typedef struct s_thread
{
	long long		k;
	int				index;
	int				p_n;
	int				died;
	int				d_t;
	int				e_t;
	int				sl_t;
	int				meals_n;
	long long		start_t;
	t_forks			*f;
	long long		last_eating;
	struct timeval	tv;
}	t_thread;

typedef struct s_philo
{
	int				i;
	int				in;
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
	long long		time;
	struct timeval	tv;
	struct timezone	tz;
	pthread_mutex_t	mutex;
}	t_philo;

int		pars(t_philo *p, char *argv[]);
long	ph_atoi(char *str, t_philo *p);
int		ft_isdigit_ph(char *str);
void	exit_message(void);
int		ft_isascii(int c);
void	ignore_zero(char *str, t_philo *p);
void	*routine(void *);
void	threads_create(t_philo *p, t_forks *f);
void	thread_init(t_philo *p, t_forks *f);
void	init(t_philo *p);
void	init_forks(t_forks *f, int philos_num);
void	creating_threads(t_philo *p, t_forks *f);
void	eating(t_thread *p, int index, long long time);
void	sleeping(t_thread *p, int index, long long time);
void	died(t_thread *p, int index, long long time);
void	thinking(t_thread *p, int index, long long time);
void	took_fork(t_thread *p, int index, long long time);
void	taking_forks(t_forks *f, int index);
int		check_for_forks(t_forks *f, int index);
void	return_forks(t_forks *f, int index);
void	ft_usleep(t_thread *p, int l);
int		check_if_died(t_thread *p);
#endif