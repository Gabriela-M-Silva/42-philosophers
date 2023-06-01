/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:06:05 by gde-mora          #+#    #+#             */
/*   Updated: 2023/05/31 02:21:19 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

int	main(int argc, char **argv) //n pode usar exit no mandatorio
{
	t_table data;

	ft_bzero(&data, sizeof(t_table));
	if (!validate_args(argc, argv))
		return (0);
	init_table(&data, argc, argv);
	start_simulation(&data);
	return (0);
}
