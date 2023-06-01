/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 07:29:18 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/01 07:36:23 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

int	check_dead(t_philo *philo)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->data->is_philo_dead == 1)
		result = 1;
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (result);
}
