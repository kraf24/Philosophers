/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:37:27 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/08/10 16:06:28 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc < 5)
	{
		printf("pipi pupu uuuuu");
		return (0);
	}
	if (ft_atoi(argv[1]) > 300)
	{
		printf("error");
		return (0);
	}
	data = malloc(sizeof(t_data) * 1);
	if (init(argv, argc, data))
		return (-1);
	ending_check(data);
}
