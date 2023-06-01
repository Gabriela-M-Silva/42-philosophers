/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 05:23:18 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/01 08:31:13 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void	*check_table(void *p)
{
	t_table		*data;
	int			i;

	data = (t_table *)p;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&data->meal_mutex);
		if (get_current_time() - data->philos[i].last_meal >= data->time_to_die)
		{
			pthread_mutex_lock(&data->dead_mutex);
			data->is_philo_dead = 1;
			pthread_mutex_unlock(&data->dead_mutex);
			printf("%ld %d died\n", \
				get_current_time() - data->start_time, data->philos[i].id + 1);
			pthread_mutex_unlock(&data->meal_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&data->meal_mutex);
		i++;
		if (i == data->number_of_philosophers)
			i = 0;
		//usleep(2000); //qual valor?
	}
}
