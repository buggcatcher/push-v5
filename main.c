/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:52:26 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/05 23:52:33 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodes	*ft_createstack_a(char **args)
{
	t_nodes	*stack_a;
	t_nodes	*value;
	int		num;
	int		i;

	stack_a = NULL;
	i = 0;
	while (args[i] != NULL)
	{
        num = ft_atoi_minmax(args[i]);
		value = ft_lstnew_int(num);
        if (!value)
        {
            ft_printf("Error: Memory allocation failed\n");
            exit(1);
        }
		ft_lstadd_back_int(&stack_a, value);
		i++;
	}
	return (stack_a);
}

int     ft_create_temp_array(t_nodes *stack, int **array)
{
    int		len;
	t_nodes	*current;
    int		i;

    len = ft_lstsize_int(stack);
    current = stack;
    i = 0;
    *array = malloc(sizeof(int) * len);
    if (!*array)
    {
        ft_printf("Error: Memory allocation failed\n");
        exit(1);
    }
	while (current)
	{
		(*array)[i++] = current->value;
		current = current->next;
	}
    return (i);
}

int	main(int argc, char **argv)
{
    t_nodes *stack_a;
    t_nodes *stack_b;
    char **args;
    int free_flag;
    int *temp_array;
    int len;
    int stack_size;
    int *array;

    stack_a = NULL;
    stack_b = NULL;
    temp_array = NULL;
    len = 0;
    array = NULL;
    // check argv for errors
    ft_atoi_minmax(argv[0]);
	initialize_stacks(argc, argv, &stack_a, &stack_b, &free_flag, &args);
	validate_stack(stack_a, free_flag, args);
    stack_size = ft_lstsize_int(stack_a);
    array = malloc(sizeof(int) * stack_size);
    process_stack(array, free_flag, *args, stack_a, &temp_array);
    push_chunks(&stack_a, &stack_b, stack_size);
	sort_stacks(&stack_a, &stack_b);
    rotate_to_min(&stack_a);
    cleanup(array, args, free_flag, stack_a, stack_b);
    return (0);
}
