/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:11:23 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/05 23:30:10 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(const char *message)
{
	ft_printf("Error: %s\n", message);
	exit(1);
}

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
			handle_error("out of range");
		}
		result = result * 10 + str[*index] - '0';
		if (result > (unsigned long)INT_MAX)
		{
			handle_error("out of range");
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
		handle_error("out of range");
	}
	return (sign * (int)result);
}
