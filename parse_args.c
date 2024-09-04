/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:57:55 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/04 17:44:14 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

int	ft_isdup(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_order_check(t_nodes *stack)
{
	t_nodes	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
		{
			return (0);
		}
		current = current->next;
	}
	if (current != NULL)
		return (1);
	return (0);
}

char	**ft_usage_check(int argc, char **argv)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
		{
			ft_printf("Error: Memory allocation failed\n");
			free_split(args);
			exit(1);
		}
	}
	else
	{
		args = argv + 1;
		if (argc == 1)
		{
			ft_printf("Usage: ./push_swap <numbers>\n");
			free_split(args);
			exit(1);
		}
	}
	return (args);
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
            ft_printf("Error: Invalid stack. Only numbers allowed\n");
            if (argc == 2)
				free_split(args);
            exit(1);
        }
        tmp = ft_atoi_minmax(args[i]);
        if (ft_isdup(tmp, args, i))
        {
            ft_printf("Error: Invalid stack. Contains duplicate\n");
            if (argc == 2)
				free_split(args);
            exit(1);
        }
    }
    return (args);
}

int validate_stack(void *stack_a, int free_flag, void *args)
{
    if (ft_order_check(stack_a) || ft_lstsize_int(stack_a) == 1)
    {
        ft_printf("Error: stack already ordered\n");
        if (free_flag)
            free(args);
        exit(1);
    }

    if (!stack_a)
    {
        ft_printf("Error: No stack found\n");
        if (free_flag)
            free(args);
        exit (1);
    }

    return 0;
}
