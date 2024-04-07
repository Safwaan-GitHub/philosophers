/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:33:05 by sanoor            #+#    #+#             */
/*   Updated: 2024/04/07 10:13:31 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

enum p_error
{
	END = 1,
	INV_ARGS = 0,
	CMD_TYPE_ERROR = -1,
	MEMORY_ALLOC_ERROR = -2,
	ERROR_TIME = -3,
	THREAD_ERROR = -4,
}

struct  s_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	int				ate_nm;
	int				status;
	int				eating;
	u_int64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo

typedef struct s_data
{
	pthread_t			*tid;
	int				philo_num;
	int				meals_nb;
	int				dead;
	int				finished;
	t_philo			*philos;
	u_int64_t		death_time;
	u_int64_t		eat_time;
	u_int64_t		start_time;
	u_int64_t		sleep_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data

void	check_data(char **av);
void	data_inits(t_list *d, int ac, char **av);
void	*data_init(t_list *d, int ac, char **av);
void	data_alloc(t_list *d);
void    free_data(t_list *d);
void    destroy_mutex(t_list *d);
void    *p_exit(t_list *d, char *av, int err);
void    p_perror(char *av, int err);
void    data_philos(t_list *d);
void    data_forks(t_list *d);

#endif
