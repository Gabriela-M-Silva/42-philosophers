/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:05:56 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/01 07:39:23 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

static void	init_forks_and_philos(t_table *data)
{
	int	i;

	i = 0;
	data->forks = malloc(data->number_of_philosophers * sizeof(pthread_mutex_t));
	data->philos = malloc(data->number_of_philosophers * sizeof(t_philo)); //colocar verificação nos malloc?
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		data->philos[i].id = i;
		data->philos[i].last_meal = data->start_time;
		data->philos[i].data = data;
		i++;
	}
}

void	init_table(t_table *data, int argc, char **argv)
{
	data->number_of_philosophers = ft_atoi(argv[1]); //podem ter erro?
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->number_of_times_to_eat = ft_atoi(argv[5]);
	data->start_time = get_current_time();
	init_forks_and_philos(data);
	pthread_mutex_init(&data->dead_mutex, NULL);
	pthread_mutex_init(&data->meal_mutex, NULL);
}
