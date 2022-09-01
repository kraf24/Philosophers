/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:08:06 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/09/01 12:26:40 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philosophers(int n, t_data *data)
{
	data->is_dead = 1;
	data->philo[n].numer = n;
	data->philo[n].meal_times = 0;
	data->philo[n].left_hand = n;
	data->philo[n].right_hand = 1;
	data->philo[n].data = data;
	n--;
	while (n > 0)
	{
		data->philo[n].numer = n;
		data->philo[n].meal_times = 0;
		data->philo[n].left_hand = n;
		data->philo[n].right_hand = (n + 1);
		data->philo[n].data = data;
		n--;
	}
}

int	init_fork(int n, t_data *data)
{
	while (n > 0)
	{
		if (pthread_mutex_init(&data->fork[n], NULL))
			return (0);
		n--;
	}
	if (pthread_mutex_init(&data->meal, NULL))
		return (0);
	if (pthread_mutex_init(&data->write, NULL))
		return (0);
	return (1);
}

int	init_philo(int n, t_data *data)
{
	data->start = c_time();
	while (n > 0)
	{
		if (pthread_create(&data->philo[n].tread, NULL, \
							&philosophers, &data->philo[n]))
			return (0);
		data->philo[n].lst_meal = c_time();
		n--;
	}
	return (1);
}

int	init(char *argv[], int argc, t_data *data)
{
	data->num_of_philo = ft_atoi(argv[1]);
	if (data->num_of_philo <= 0)
		return (3);
	data->time_to_die = ft_atoi(argv[2]);
	if (data->time_to_die <= 0)
		return (4);
	data->time_to_eat = ft_atoi(argv[3]);
	if (data->time_to_eat <= 0)
		return (5);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->time_to_sleep <= 0)
		return (6);
	if (argc == 6)
		data->num_of_meals = ft_atoi(argv[5]);
	else
		data->num_of_meals = -1;
	if (!init_fork(data->num_of_philo, data))
		return (1);
	init_philosophers(data->num_of_philo, data);
	if (!init_philo(data->num_of_philo, data))
		return (2);
	return (0);
}
