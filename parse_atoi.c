/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:11:23 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 14:30:57 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_sign(const char *str, int *index)
{
	int	sign;
	int	count_minus;

	sign = 1;
	count_minus = 0;
	while (str[*index] == '+' || str[*index] == '-')
	{
		if (str[*index] == '-')
			count_minus++;
		(*index)++;
	}
	if (count_minus % 2 != 0)
		sign = -1;
	return (sign);
}


unsigned long	parse_number(const char *str, int *index)
{
	unsigned long	result;

	result = 0;
	while (ft_isdigit(str[*index]))
	{
		if (result > (unsigned long)INT_MAX)
		{
			error_handler("range");
		}
		result = result * 10 + str[*index] - '0';
		if (result > (unsigned long)INT_MAX)
		{
			error_handler("range");
		}
		(*index)++;
	}
	return (result);
}

int	ft_atoi_minmax(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
		i++;
	}
	sign = parse_sign(str, &i);
	result = parse_number(str, &i);
	if (sign == -1 && result > (unsigned long)INT_MIN)
	{
		error_handler("range");
	}
	return (sign * (int)result);
}
