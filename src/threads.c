/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 09:50:25 by sanoor            #+#    #+#             */
/*   Updated: 2024/04/07 10:50:02 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	one_philo(t_data *d)
{
	d->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
		return (p_error(d, NULL, THREAD_ERORR));
	pthread_detach(d->tid[0]);
	while (d->dead == 0)
		ft_usleep(0);
	p_error(d, NULL, 2);
}
