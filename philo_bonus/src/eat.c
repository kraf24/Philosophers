/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:44:54 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/08/10 16:07:54 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	meal(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	sem_wait(data->forks);
	print_output(philo, " has taken a fork");
	sem_wait(data->forks);
	print_output(philo, " has taken a fork");
	print_output(philo, "is eating");
	absolute_sleep(data->time_to_eat);
	philo->lst_meal = c_time();
	philo->meal_times++;
	sem_post(data->forks);
	sem_post(data->forks);
}
