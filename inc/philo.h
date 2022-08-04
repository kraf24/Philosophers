#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	unsigned long long	lst_meal;
	pthread_mutex_t		left_hand;
	pthread_mutex_t		right_hand;
	pthread_t			tread;
	int					numer;
	int					meal_times;
	struct s_data		*data;
}		t_philo;

typedef struct s_data
{
	unsigned long long	start;
	pthread_mutex_t		*fork;
	pthread_mutex_t		meal; //?
	pthread_mutex_t		write;
	t_philo 			*philo;
	int					num_of_philo;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
}		t_data;

unsigned long long	c_time(void);
void				*some_function(void *arg);
void				init_philosophers(int n, t_data *data);
void				meal(t_philo *philo);
void				*philosophers(void *arg);
int					ft_atoi(const char *str);
void				init(char *argv[], t_data *data);
void				exit_function(int n, t_data *data);
void				destroy(int n, t_data *data);

void				print_output(t_philo *philo, char *message);

int					diff(unsigned long long pre, unsigned long long post);

#endif