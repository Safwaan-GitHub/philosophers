/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:52:59 by sanoor            #+#    #+#             */
/*   Updated: 2024/04/06 17:05:09 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_data(t_list *d)
{
	if (d->tid)
		free(d->tid);
	if (d->philos)
		free(d->philos);
	if (d->forks)
		free(d->forks);
}

void	destroy_mutex(t_list *d)
{
	int	i;

	i = -1;
	while (d->philo_num > ++i)
	{
		pthread_mutex_destroy(&d->forks[i]);
		pthread_mutex_destroy(&d->philos[i].lock);
	}
	pthread_mutex_destroy(&d->lock);
	pthread_mutex_destroy(&d->write);
}

void	*p_exit(t_list *d, char *av, int err)
{
	if (err < 1 || av)
		p_perror(av, err);
	if (d)
	{
		destroy_mutex(d);
		free_data(d);
	}
	exit(0);
	return (0);
}

void	p_perror(char *av, int err)
{
	if (err == NO_CMD)
		printf("Error Argument Vector incorrect\n");
	if (err == CMD_TYPE_ERROR)
		printf("Error Argument Vector contains incorrect lexicon\n");
	if (err == MEMORY_ALLOC_ERROR)
		printf("Eerror Memory Allocation failure\n");
	if (av && CMD_TYPE_ERROR)
		printf("%s\n", av);
}
