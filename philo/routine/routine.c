/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:28:12 by gde-mora          #+#    #+#             */
/*   Updated: 2023/06/01 09:44:03 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philosophers.h"

static void	aux_mutex_eating(t_philo *philo, int locked)
{
	if (locked == 0 && philo->id + 1 < philo->data->number_of_philosophers)
	{
		pthread_mutex_lock(&philo->data->forks[philo->id]);
		pthread_mutex_lock(&philo->data->forks[philo->id + 1]);
	}
	else if (locked == 0)
	{
		pthread_mutex_lock(&philo->data->forks[philo->id]);
		pthread_mutex_lock(&philo->data->forks[0]);
	}
	if (locked == 1 && philo->id + 1 < philo->data->number_of_philosophers)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->id]);
		pthread_mutex_unlock(&philo->data->forks[philo->id + 1]);
	}
	else if (locked == 1)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->id]);
		pthread_mutex_unlock(&philo->data->forks[0]);
	}
}

static void	eating(t_philo *philo)
{
	aux_mutex_eating(philo, 0);
	if (!check_dead(philo))
	{
		printf("%ld %d has taken a fork\n", \
			get_current_time() - philo->data->start_time, philo->id + 1);
		pthread_mutex_lock(&philo->data->meal_mutex);
		philo->last_meal = get_current_time();
		pthread_mutex_unlock(&philo->data->meal_mutex);
		printf("%ld %d is eating\n", \
			get_current_time() - philo->data->start_time, philo->id + 1);
		usleep(philo->data->time_to_eat * 1000);
	}
	aux_mutex_eating(philo, 1);
}

static void	sleeping(t_philo *philo)
{
	if (check_dead(philo))
		return ;
	printf("%ld %d is sleeping\n", \
		get_current_time() - philo->data->start_time, philo->id + 1);
	usleep(philo->data->time_to_sleep * 1000);
}

static void	thinking(t_philo *philo)
{
	if (check_dead(philo))
		return ;
	printf("%ld %d is thinking\n", \
		get_current_time() - philo->data->start_time, philo->id + 1);
}

void	*routine(void *p)
{
	t_philo	*philo;
	int		eat_times;

	philo = (t_philo *)p;
	eat_times = 0;
	while (!check_dead(philo) && \
		(eat_times++ < philo->data->number_of_times_to_eat || \
		philo->data->number_of_times_to_eat == 0))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	if (!check_dead(philo))
	{
		pthread_mutex_lock(&philo->data->full_mutex);
		philo->eat_full = 1;
		pthread_mutex_unlock(&philo->data->full_mutex);
	}
	return (NULL);
}
