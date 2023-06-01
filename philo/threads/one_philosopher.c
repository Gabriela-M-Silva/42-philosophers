/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philosopher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:15:46 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/01 08:45:46 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

static void	*mini_routine(void *data)
{
	t_table	*aux;

	aux = (t_table *)data;
	aux->start_time = get_current_time();
	printf("%d 1 has taken a fork\n", 0);
	usleep(aux->time_to_die * 1000);
	printf("%ld 1 died\n", get_current_time() - aux->start_time);
	return (NULL);
}

void	one_thread(t_table *data)
{
	pthread_t	philo1;

	pthread_create(&philo1, NULL, &mini_routine, data);
	pthread_join(philo1, NULL);
}
