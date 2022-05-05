/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:21:52 by glaverdu          #+#    #+#             */
/*   Updated: 2021/10/30 11:38:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	destroy_philos(t_threads_data *threads, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->num_of_philo)
	{
		pthread_join(threads->philos[i]->id, NULL);
		i++;
	}
}

static void	free_philos(t_threads_data *threads, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->num_of_philo)
	{
		free(threads->philos[i]);
		i++;
	}
}

static void	destroy_mutexes(t_threads_data *threads, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->num_of_philo)
	{
		pthread_mutex_destroy(&threads->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&threads->print_lock);
	pthread_mutex_destroy(&threads->died_lock);
}

void	threads_cleaning_wrapper(t_threads_data *threads, t_param *param)
{
	destroy_philos(threads, param);
	free_philos(threads, param);
	destroy_mutexes(threads, param);
	free(threads->philos);
	free(threads->fork);
}
