/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdamoha <abdamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:20:06 by abdamoha          #+#    #+#             */
/*   Updated: 2023/05/04 19:15:57 by abdamoha         ###   ########.fr       */
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
	long long		current;
	int				*forks;
	int				*arr;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	fork;
	pthread_mutex_t	mu;
	pthread_mutex_t	e;
	pthread_mutex_t	die;
	pthread_mutex_t	pri;
	pthread_mutex_t	checker;
	pthread_mutex_t	loop_d;
	pthread_mutex_t	every_t;
	pthread_mutex_t	last_e;
	pthread_mutex_t	bye_l;
	int				*status;
	int				bye;
}	t_forks;

typedef struct s_thread
{
	long long		k;
	int				i;
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
	long long		current;
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
	long long		time;
	struct timeval	tv;
	pthread_mutex_t	mutex;
}	t_philo;

int			pars(t_philo *p, char *argv[]);
long		ph_atoi(char *str, t_philo *p);
int			ft_isdigit_ph(char *str);
int			ft_isascii(int c);
void		ignore_zero(char *str, t_philo *p);
void		*routine(void *t);
int			threads_create(t_philo *p, t_forks *f);
void		thread_init(t_philo *p, t_forks *f);
void		init(t_philo *p);
void		init_forks(t_forks *f, int philos_num);
int			creating_threads(t_philo *p, t_forks *f);
void		eating(t_thread *p, int index, long long time);
void		sleeping(t_thread *p, int index, long long time);
void		died(t_thread *p, int index, long long time);
void		thinking(t_thread *p, int index, long long time);
int			took_fork(t_thread *p, int index, long long time);
void		taking_forks(t_forks *f, int index);
int			check_for_forks(t_forks *f, int index);
void		return_forks(t_forks *f, int index);
void		ft_usleep(t_thread *p, int l);
int			check_if_died(t_thread *p);
int			check_dying(t_philo *p);
long long	ft_gettime(void);
int			check_if_died(t_thread *p);
int			join_threads(t_philo *p);
int			everytime_check(t_forks *f);
void		unlock_when_die(t_thread *p);
int			about_to_die(t_thread *p, int index);
void		destroy_everything(t_philo *p);
void		init_status(t_forks *f, int philos_num);
void		init_mutexs(t_forks *f);
void		routine2(t_thread *p);
int			inside_checker(t_thread *p);
int			status_checker(t_thread *p);
void		unlock_inside(t_forks *f, int i);
int			check_if_taken(t_forks *f);
void		greedy_shit(t_thread *p);
int			greedy_shit_checker(t_thread *p);
#endif