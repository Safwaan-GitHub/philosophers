/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:44:20 by sanoor            #+#    #+#             */
/*   Updated: 2024/04/06 18:31:21 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_data(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				j++;
			if (av[i][j] < '0' && av[i][j] > '9')
				return (p_error(NULL, av[i], CMD_TYPE_ERROR));
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	d;

	if (ac != 4 || ac != 5)
		return (*(int *)p_exit(NULL, NULL, INV_ARGS));
	check_data(av);
	data_init(&d, ac, av);
	if (d->philo_num == 1)
		one_philo(d);
}
