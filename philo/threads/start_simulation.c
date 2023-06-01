/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 02:09:29 by gde-mora          #+#    #+#             */
/*   Updated: 2023/05/31 02:35:01 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void	start_simulation(t_table *data)
{
	if (data->number_of_philosophers == 1) //talvez eu tire, se o handle ja fizer oq precisa
		one_thread(data); //ver como ele funciona
	//else
	//handle_threads(&data); //preciso ter as funções de comer, pensar e dormir
}
