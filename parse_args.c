/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:57:55 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 15:57:47 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void free_args(char **args)
{
    int i = 0;
    if (args)
    {
        while (args[i])
        {
            free(args[i]);
            i++;
        }
        free(args);
    }
}

void error_handler(const char *error_type)
{
    if (ft_strcmp(error_type, "mem") == 0)
        ft_printf("Error: Memory allocation failed\n");
    else if (ft_strcmp(error_type, "invalid") == 0)
        ft_printf("Error: Invalid arguments\n");
    else if (ft_strcmp(error_type, "usage") == 0)
        ft_printf("Usage: ./push_swap <numbers>\n");
    else if (ft_strcmp(error_type, "range") == 0)
        ft_printf("Error: Number out of range\n");
    else if (ft_strcmp(error_type, "char") == 0)
        ft_printf("Error: Only numbers allowed\n");
    else if (ft_strcmp(error_type, "dup") == 0)
        ft_printf("Error: Contains duplicate\n");
    else if (ft_strcmp(error_type, "order") == 0)
        ft_printf("Error: stack already ordered\n");
    else if (ft_strcmp(error_type, "no_stack") == 0)
        ft_printf("Error: No stack found\n");
    exit(1);
}

int	ft_isdup(int num, char **argv, int i)
{
	int j = 0;
	while (argv[j])
	{
		if (j != i && ft_atoi_minmax(argv[j]) == num)
			return (1);
		j++;
	}
	return (0);
}

char **ft_arg_checker(int argc, char **argv)
{
    int i;
    long tmp;
    char **args;

    i = 0;
    args = ft_usage_check(argc, argv);
    while (args[++i])
    {
        if (!ft_isnum(args[i]))
        {
            if (argc == 2)
				free_split(args);
            error_handler("char");
        }
        tmp = ft_atoi_minmax(args[i]);
        if (ft_isdup(tmp, args, i))
        {
            if (argc == 2)
				free_split(args);
            error_handler("dup");
        }
    }
    return (args);
}

int validate_stack(t_nodes *stack_a, int free_flag, char **args)
{
    if (ft_order_check(stack_a) || ft_lstsize_int(stack_a) == 1)
    {
        while (stack_a)
        {
            t_nodes *temp = stack_a;
            stack_a = stack_a->next;
            free(temp);
        }
        if (free_flag)
            free_split(args);
        error_handler("order");
    }
    if (!stack_a)
    {

        if (free_flag)
            free_split(args);
        error_handler("no_stack");
    }
    return (0);
}


