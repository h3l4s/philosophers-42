/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:21:52 by glaverdu          #+#    #+#             */
/*   Updated: 2021/10/30 11:38:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	sleeping(t_philo *philo)
{
	int	current_time;
	int	philo_pos;

	philo_pos = philo->pos + 1;
	current_time = get_time_in_ms();
	pthread_mutex_lock(philo->print_lock);
	if (!check_if_philo_died(philo))
		print_philo_status(SLEEP, current_time - philo->start_time, philo_pos);
	pthread_mutex_unlock(philo->print_lock);
	ms_sleep(philo->tt_sleep);
}
