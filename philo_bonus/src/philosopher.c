/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:46:27 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/08/31 15:02:20 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*philosophers(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	philo->lst_meal = c_time();
	if (data->num_of_philo == 1)
	{
		absolute_sleep(data->time_to_die);
		print_output(philo, "died");
		return (NULL);
	}
	while (data->is_dead)
	{
		meal(philo);
		if (philo->meal_times == data->num_of_meals)
			break ;
		print_output(philo, "is sleeping");
		absolute_sleep(data->time_to_sleep);
		print_output(philo, "is thinking");
	}
	exit(0);
}
