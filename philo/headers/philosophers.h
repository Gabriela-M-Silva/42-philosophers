/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:06:15 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/01 08:22:29 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_table
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_to_eat;
	long int		start_time;
	int				is_philo_dead;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	*forks;
	struct s_philo	*philos;
}	t_table;

typedef struct s_philo
{
	int				id;
	long int		last_meal;
	struct s_table	*data;
}	t_philo;

// validate_args functions
int			validate_args(int argc, char **argv);
int			ft_atoi(const char *str);
char		*ft_itoa_u(unsigned int n);
int			ft_strcmp(char *s1, char *s2);

// init functions
void		init_table(t_table *data, int argc, char **argv);
void		ft_bzero(void *s, size_t n);
long int	get_current_time(void);

// threads functions
void		start_simulation(t_table *data);
void		one_thread(t_table *data);
void		create_threads(t_table *data);
void		free_data(t_table *data);

// routine functions
void		*routine(void *p);
void		*check_table(void *p);
int			check_dead(t_philo *philo);

#endif