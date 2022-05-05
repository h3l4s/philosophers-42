/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:21:52 by glaverdu          #+#    #+#             */
/*   Updated: 2021/10/30 11:38:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*life_of_1_philo(void *thread_infos)
{
	t_philo	*philo;

	philo = (t_philo *)(thread_infos);
	get_fork(philo, LEFT_FORK);
	put_fork_down(philo, LEFT_FORK);
	while (!check_if_philo_died(philo))
		;
	return (0);
}

void	*life_of_philo(void *thread_infos)
{
	t_philo	*philo;

	philo = (t_philo *)(thread_infos);
	if (philo->pos % 2)
		usleep(900);
	while (!philo_is_full(philo) && !check_if_philo_died(philo))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}
