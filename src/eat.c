/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:44:54 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/08/04 17:06:27 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_hand);
	print_output(philo, " has taken a fork");

	pthread_mutex_lock(&philo->right_hand);
	print_output(philo, " has taken a fork");
	
//	pthread_mutex_lock(&philo->data->meal);
	print_output(philo, "is eating");
	philo->lst_meal = c_time();
//	pthread_mutex_unlock(&philo->data->meal);
		
	usleep(philo->data->time_to_eat * 1000);
	philo->meal_times++;
	pthread_mutex_unlock(&philo->right_hand);
	pthread_mutex_unlock(&philo->left_hand);
}