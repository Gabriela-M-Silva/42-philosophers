/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 05:41:34 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/01 06:57:20 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void	create_threads(t_table *data)
{
	pthread_t	*philos;
	pthread_t	observ;
	int			i;

	i = 0;
	philos = malloc(data->number_of_philosophers * sizeof(pthread_t));
	while (i < data->number_of_philosophers)
	{
		pthread_create(&philos[i], NULL, &routine, &data->philos[i]);
		i++;
	}
	pthread_create(&observ, NULL, &check_table, data);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_join(philos[i], NULL);
		i++;
	}
	pthread_join(observ, NULL);
	free(philos);
}
