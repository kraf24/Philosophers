/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:08:06 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/08/11 15:40:04 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_philosophers(int n, t_data *data)
{
	data->is_dead = 1;
	while (n > 0)
	{
		data->philo[n].numer = n;
		data->philo[n].meal_times = 0;
		data->philo[n].data = data;
		n--;
	}
}

int	init_sem(int n, t_data *data)
{
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("meal");
	sem_unlink("death");
	data->forks = sem_open("forks", O_CREAT, S_IRWXU, data->num_of_philo);
	data->meal = sem_open("meal", O_CREAT, S_IRWXU, 1);
	data->write = sem_open("write", O_CREAT, S_IRWXU, 1);
	data->death = sem_open("death", O_CREAT, S_IRWXU, 1);
	return (1);
}

int	init_philo(int n, t_data *data)
{
	data->start = c_time();
	while (n > 0)
	{
		data->philo[n].proces = fork();
		if (data->philo[n].proces == 0)
			philosophers(&(data->philo[n]));
		n--;
	}
	return (1);
}

int	init(char *argv[], int argc, t_data *data)
{
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_of_meals = ft_atoi(argv[5]);
	else
		data->num_of_meals = -1;
	if (!init_sem(data->num_of_philo, data))
		return (1);
	init_philosophers(data->num_of_philo, data);
	if (!init_philo(data->num_of_philo, data))
		return (2);
	return (0);
}
