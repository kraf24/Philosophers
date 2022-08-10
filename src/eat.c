/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:44:54 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/08/10 15:12:59 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	meal(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork[philo->left_hand]);
	print_output(philo, " has taken a fork");
	pthread_mutex_lock(&data->fork[philo->right_hand]);
	print_output(philo, " has taken a fork");
	pthread_mutex_lock(&philo->data->meal);
	print_output(philo, "is eating");
	philo->lst_meal = c_time();
	pthread_mutex_unlock(&philo->data->meal);
	absolute_sleep(data->time_to_eat);
	philo->meal_times++;
	pthread_mutex_unlock(&data->fork[philo->right_hand]);
	pthread_mutex_unlock(&data->fork[philo->left_hand]);
}
