/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:51:36 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/08/11 16:06:22 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	exit_function(int n, t_data *data)
{
	int	i;
	int ret;

	i = 0;
	while (i <= n)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
				i =0;
				while (i++ < data->num_of_philo)
					kill(data->philo[i].proces, 15);
				break;		
		}
		i++;
	}
}

void	destroy(int n, t_data *data)
{
	sem_close(data->forks);
	sem_close(data->meal);
	sem_close(data->write);
	sem_unlink("forks");
	sem_unlink("write");
	sem_unlink("meal");
}

void	ending_check(t_data *data)
{
	exit_function(data->num_of_philo, data);
	destroy(data->num_of_philo, data);
	free(data);
}
