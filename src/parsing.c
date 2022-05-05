/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:21:52 by glaverdu          #+#    #+#             */
/*   Updated: 2021/10/30 11:38:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	arguments_are_valid(char **args, int nb_args)
{
	int	i;
	int	j;
	int	err;

	i = 0;
	while (++i < nb_args)
	{
		err = 0;
		j = 0;
		if (!is_within_int_range(ft_atol(args[i], &err))
			|| ft_atol(args[i], &err) < 1)
			return (1);
		else
			ft_atol(args[i], &err);
		if (err != 0)
			return (1);
		while (args[i][j])
			if (!is_digit(args[i][j++]))
				return (1);
	}
	return (0);
}
