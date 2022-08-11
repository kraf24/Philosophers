/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:14:23 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/08/10 15:14:32 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	unsigned long long	lst_meal;
	int					left_hand;
	int					right_hand;
	pthread_t			tread;
	int					numer;
	int					meal_times;
	struct s_data		*data;
}		t_philo;

typedef struct s_data
{
	unsigned long long	start;
	pthread_mutex_t		fork[300];
	pthread_mutex_t		meal;
	pthread_mutex_t		write;
	t_philo				philo[300];
	int					is_dead;
	int					num_of_meals;
	int					num_of_philo;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
}		t_data;

unsigned long long	c_time(void);
void				*some_function(void *arg);
void				meal(t_philo *philo);
void				*philosophers(void *arg);
int					ft_atoi(const char *str);
int					init(char *argv[], int argc, t_data *data);
void				exit_function(int n, t_data *data);
void				destroy(int n, t_data *data);

void				print_output(t_philo *philo, char *message);

void				ending_check(t_data *data);

int					diff(unsigned long long pre, unsigned long long post);

void				absolute_sleep(int time);

#endif