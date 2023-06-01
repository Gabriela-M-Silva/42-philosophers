/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:48:22 by gde-mora          #+#    #+#             */
/*   Updated: 2023/05/30 23:08:17 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

static int	is_numeric(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				if (!(j == 0 && argv[i][j] == '+'))
				{
					printf("Error.\nInvalid arguments.\n");
					printf("Try numeric and positive arguments.\n");
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_size_int(char **argv)
{
	int		i;
	int		number;
	int		point;
	char	*aux;

	i = 1;
	while (argv[i])
	{
		point = 0;
		if (argv[i][0] == '+')
			point = 1;
		number = ft_atoi(argv[i]);
		aux = ft_itoa_u((unsigned int)number);
		if (ft_strcmp(&argv[i][point], aux) != 0)
		{
			printf("Error.\nArgument length is greater than int type.\n");
			free(aux);
			return (0);
		}
		free(aux);
		i++;
	}
	return (1);
}

int	validate_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error.\nInvalid number of arguments. \nTry: \n./philo ");
		printf("number_of_philosophers time_to_die time_to_eat time_to_sleep");
		printf(" [number_of_times_each_philosopher_must_eat]\n");
		return (0);
	}
	if (!is_numeric(argv) || !is_size_int(argv))
		return (0);
	return (1);
}
