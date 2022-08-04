/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:46:27 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/08/04 17:12:55 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void *philosophers(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while(1)
	{
		meal(philo);
		print_output(philo, "is sleeping");
		usleep(data->time_to_sleep * 1000);
		print_output(philo, "is thinking");
		if(diff(c_time(), data->philo[1].lst_meal) >= data->time_to_die)
		{
			break;	
		}
	}
	return (NULL);
}