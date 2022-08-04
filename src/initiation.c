/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:08:06 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/08/04 16:51:28 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

void	init_philosophers(int n, t_data *data)
{
	data->philo[n].numer = n;
	data->philo[n].lst_meal = 0;
	data->philo[n].meal_times = 0;
	data->philo[n].left_hand = data->fork[n];
	data->philo[n].right_hand = data->fork[1];
	data->philo[n].data = data;
	n--;
	while (n > 0)
	{
		data->philo[n].numer = n;
		data->philo[n].lst_meal = 0;
		data->philo[n].meal_times = 0;
		data->philo[n].left_hand = data->fork[n];
		data->philo[n].right_hand = data->fork[(n + 1)];
		data->philo[n].data = data;
		n--;
	}
}

void	init_fork(int n, t_data *data)
{
	while (n > 0)
	{
		pthread_mutex_init(&data->fork[n], NULL);
		n--;
	}
	pthread_mutex_init(&data->meal, NULL);

	pthread_mutex_init(&data->write, NULL);
}

void init_philo(int n,t_data *data)
{
	data->start = c_time();
	while (n > 0)
	{
		pthread_create(&data->philo[n].tread, NULL, &philosophers, &data->philo[n]);
		data->philo[n].lst_meal = c_time();
		n--;
	}
}

void init(char *argv[], t_data *data)
{
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	

	
	init_fork(data->num_of_philo, data);
	init_philosophers(data->num_of_philo, data);
	init_philo(data->num_of_philo, data);
}