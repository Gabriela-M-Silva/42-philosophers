/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:02:59 by gde-mora          #+#    #+#             */
/*   Updated: 2023/05/30 23:08:28 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i]) && (s2[i]))
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

static size_t	ft_counter_digits_itoa_u(unsigned int n)
{
	size_t	counter;

	counter = 1;
	while (n / 10)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*str;
	size_t	i;

	i = ft_counter_digits_itoa_u(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i--)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signal;
	int	res;

	i = 0;
	signal = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * signal);
}
