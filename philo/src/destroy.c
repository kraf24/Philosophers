/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:51:36 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/08/10 15:13:37 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	exit_function(int n, t_data *data)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		pthread_join(data->philo[n].tread, NULL);
		i++;
	}
}

void	destroy(int n, t_data *data)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		pthread_detach(data->philo[n].tread);
		pthread_mutex_destroy(&data->fork[n]);
		i++;
	}
	pthread_mutex_destroy(&data->write);
}

void	ending_check(t_data *data)
{
	exit_function(data->num_of_philo, data);
	destroy(data->num_of_philo, data);
	free(data);
}
