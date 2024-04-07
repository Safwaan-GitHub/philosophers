/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:47:53 by sanoor            #+#    #+#             */
/*   Updated: 2024/04/06 18:32:51 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	data_philos(t_list *d)
{
	int	i;

	i = 0;
	while (i < d->philos_num)
	{
		d->philos[i].data = d;
		d->philos[i].id = i + 1;
		d->philos[i].time_to_die = d->death_time;
		d->philos[i].status = 0;
		d->philos[i].eating = 0;
		d->philos[i].ate_nm = 0;
		pthread_mutex_t(&d->philos[i].lock, NULL);
		i++;
	}
}

void	data_forks(t_list *d)
{
	int	i;

	i = -1;
	while (d->philo_num > ++i)
		pthread_mutex_t(&d->forks[i], NULL);
	d->philos[0].r_fork = d->forks[0];
	d->philos[0].l_fork = d->forks[d->philo_num - 1];
	i = 1;
	while (i < d->philo_num)
	{
		d->philos[i].r_fork = d->forks[i];
		d->philos[i].l_fork = d->forks[i - 1];
		i++;
	}
}

void	data_alloc(t_list *d)
{
	d->tid = malloc((sizeof(pthread_t) * (d->philo_num)));
	d->forks = malloc((sizeof(pthread_mutex_t) * (d->philo_num)));
	d->philos = malloc((sizeof(t_philo) * (d->philo_num)));
	if (d->tid == NULL || d->forks == NULL || d->philos == NULL)
		p_error(d, NULL, MEMORY_ALLOC_ERROR);
}

void	data_inits(t_list *d, int ac, char **av)
{
	d->philo_num = (int) ft_atoi(av[1]);
	d->death_time = (u_int64_t) ft_atoi(av[2]);
	d->eat_time = (u_int64_t) ft_atoi(av[3]);
	d->sleep_time = (u_int64_t) ft_atoi(av[4]);
	if (ac == 6)
		d->meals_nb = (int) av[5];
	else
		d->meals_nb = -1;
	if (d->philo_num <= 0 || d->philo_num > 200 || d->death_time < 0
		|| d->eat_time < 0 || d->sleep_time < 0)
		p_error(NULL, NULL, CMD_TYPE_ERROR);
	d->dead = 0;
	d->finished = 0;
	pthread_mutex_init(&d->lock, NULL);
	pthread_mutex_init(&d->write, NULL);
}

void	*data_init(t_list *d, int ac, char **av)
{
	data_inits(d, ac, av);
	data_alloc(d);
	data_forks(d);
	data_philos(d);
}
