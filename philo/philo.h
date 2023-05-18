/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:06:15 by gde-mora          #+#    #+#             */
/*   Updated: 2023/05/17 21:43:54 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_data
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_to_eat;
}	t_data;

// philo utils
int		ft_atoi(const char *str);
char	*ft_itoa_u(unsigned int n);
int		ft_strcmp(char *s1, char *s2);

// philo functions
void	one_thread(t_data *data);

#endif