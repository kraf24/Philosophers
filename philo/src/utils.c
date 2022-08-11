/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:37:12 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/08/11 15:21:03 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	chek_minus(const char *str, int *num)
{
	while (str[*num] >= 0 && (str[*num] == 32 || str[*num] == '\t'
			|| str[*num] == '\n' || str[*num] == '\r'
			|| str[*num] == '\v' || str[*num] == '\f'))
	{
		++*num;
	}
	if (str[*num] == '-')
	{
		++*num;
		return (1);
	}
	else if (str[*num] == '+')
	{
		++*num;
		return (0);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	num;
	int	b;

	a = 0;
	num = 0;
	b = chek_minus(str, &num);
	while (str[num] != '\0')
	{
		if (str[num] > '9' || str[num] < '0')
		{
			break ;
		}
		a = (a * 10) + (str[num] - '0');
		++num;
	}
	if (b == 1)
	{
		a = (-1) * a;
	}
	return (a);
}

void	print_output(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->write);
	if (diff(c_time(), philo->lst_meal) >= philo->data->time_to_die \
											&& philo->data->is_dead)
	{
		philo->data->is_dead = 0;
		printf("%d ", diff(c_time(), philo->data->start));
		printf("%d ", philo->numer);
		printf("%s\n", "died");
		pthread_mutex_unlock(&philo->data->write);
		return ;
	}
	if (philo->data->is_dead)
	{
		printf("%d ", diff(c_time(), philo->data->start));
		printf("%d ", philo->numer);
		printf("%s\n", message);
	}
	pthread_mutex_unlock(&philo->data->write);
}

void	absolute_sleep(int time)
{
	unsigned long long	i;

	i = c_time();
	while (1)
	{
		if (diff(c_time(), i) >= time)
			break ;
	}
}
