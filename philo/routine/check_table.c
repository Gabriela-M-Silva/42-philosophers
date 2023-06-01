/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 05:23:18 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/01 09:50:15 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

static int	check_finish_table(t_table *data)
{
	int	i;
	int	full_eats;

	i = 0;
	full_eats = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_lock(&data->full_mutex);
		if (data->philos[i].eat_full == 1)
			full_eats++;
		pthread_mutex_unlock(&data->full_mutex);
		i++;
	}
	if (full_eats == data->number_of_philosophers)
	{
		printf("All philosphers have finished eating\n");
		return (1);
	}
	return (0);
}

static int	set_dead(t_table *data, int i)
{
	if (get_current_time() - data->philos[i].last_meal >= data->time_to_die \
		&& data->philos[i].eat_full != 1)
	{
		pthread_mutex_lock(&data->dead_mutex);
		data->is_philo_dead = 1;
		pthread_mutex_unlock(&data->dead_mutex);
		printf("%ld %d died\n", \
			get_current_time() - data->start_time, data->philos[i].id + 1);
		pthread_mutex_unlock(&data->full_mutex);
		pthread_mutex_unlock(&data->meal_mutex);
		return (1);
	}
	return (0);
}

void	*check_table(void *p)
{
	t_table		*data;
	int			i;

	data = (t_table *)p;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&data->meal_mutex);
		pthread_mutex_lock(&data->full_mutex);
		if (set_dead(data, i))
			return (NULL);
		pthread_mutex_unlock(&data->full_mutex);
		pthread_mutex_unlock(&data->meal_mutex);
		i++;
		if (i == data->number_of_philosophers)
			i = 0;
		if (check_finish_table(data))
			break ;
		usleep(500);
	}
	return (NULL);
}
