/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:15:46 by gde-mora          #+#    #+#             */
/*   Updated: 2023/05/18 02:30:29 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *data)
{
	//usleep(data->time_to_die);
	t_data *aux = data;
	printf("%d\n", aux->number_of_philosophers);
	return (NULL);
}

void	one_thread(t_data *data)
{
	pthread_t	philo1;

	pthread_create(&philo1, NULL, &routine, data);
	pthread_join(philo1, NULL);
}
