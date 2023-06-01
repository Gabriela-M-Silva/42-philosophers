/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:56:28 by gde-mora          #+#    #+#             */
/*   Updated: 2023/05/31 01:48:30 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

long int	get_current_time(void)
{
	struct timeval	current_time;
	long int		time_in_ms;

	gettimeofday(&current_time, NULL);
	time_in_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (time_in_ms);
}
