/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 02:09:29 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/01 06:06:03 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void	start_simulation(t_table *data)
{
	if (data->number_of_philosophers == 1)
		one_thread(data);
	else
		create_threads(data);
	free_data(data);
}
