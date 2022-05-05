/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:21:52 by glaverdu          #+#    #+#             */
/*   Updated: 2021/10/30 11:38:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_lite_atoi(char *s)
{
	char	*nbr;
	int		n;
	int		i;

	nbr = (char *)s;
	i = 0;
	n = 0;
	while (nbr[i] > 47 && nbr[i] < 58)
	{
		if (nbr[i + 1] > 47 && nbr[i + 1] < 58)
			n = (n + (int)(nbr[i]) % 48) * 10;
		else
			n = (n + (int)(nbr[i]) % 48);
		i++;
	}
	return (n);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *string)
{
	int	i;

	i = 0;
	while (string && string[i])
	{
		ft_putchar(string[i]);
		i++;
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

int	get_time_in_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}
