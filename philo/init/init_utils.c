/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:58:38 by gde-mora          #+#    #+#             */
/*   Updated: 2023/05/31 00:00:59 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*aux_str;

	aux_str = (unsigned char *)s;
	while (n--)
		*aux_str++ = '\0';
}
