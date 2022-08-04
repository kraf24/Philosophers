/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:37:27 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/08/04 16:44:52 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

int main(int argc, char *argv[])
{
	t_data	*data;

	if (argc < 5)
		{
			printf("pipi pupu uuuuu");
			return (0);
		}
	
	data = malloc(sizeof(t_data) * 1);
	data->philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	data->fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	
	init(argv, data);
	exit_function(data->num_of_philo, data);
	destroy(data->num_of_philo, data);
}