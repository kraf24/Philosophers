/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:51:36 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/08/04 16:03:21 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void exit_function(int n, t_data *data)
{
	while(n > 0)
	{
		pthread_join(data->philo[n].tread, NULL);
		n--;
	}
}

void destroy(int n, t_data *data)
{
	while(n > 0)
	{
		pthread_detach(data->philo[n].tread);
		// pthread_mutex_destroy(&data->fork[n]);
		n--;
	}
	pthread_mutex_destroy(&data->meal);
	pthread_mutex_destroy(&data->write);
}