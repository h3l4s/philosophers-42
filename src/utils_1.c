/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:21:52 by glaverdu          #+#    #+#             */
/*   Updated: 2021/10/30 11:38:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	is_spaces(char c)
{
	return (c == '\t' || c == ' ');
}

static int	is_within_long_range(long long int number, int sign)
{
	if (sign < 0)
		return ((number * sign) >= LONG_MIN);
	else
		return (number <= LONG_MAX);
}

int	is_within_int_range(long long int number)
{
	return (number >= INT_MIN && number <= INT_MAX);
}

int	is_digit(char character)
{
	return (character >= '0' && character <= '9');
}

long long	ft_atol(char *str, int *error)
{
	int			sign;
	long long	n;
	int			i;

	i = 0;
	n = 0;
	sign = 1;
	while (is_spaces(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = sign * (-1);
	while (is_digit(str[i]) && is_within_int_range(n))
	{
		if (is_digit(str[i + 1]))
			n = (n + (long long)(str[i]) % 48) * 10;
		else
			n = (n + (long long)(str[i]) % 48);
		i++;
	}
	if (!is_within_long_range(n, sign))
		*error = -1;
	return (n * sign);
}
