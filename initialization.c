/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:20:50 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/06 00:11:48 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void initialize_stacks(int argc, char **argv, t_nodes **stack_a, t_nodes **stack_b, int *free_flag, char ***args)
{
    *free_flag = 0;
    *args = ft_arg_checker(argc, argv);

    if (argc == 2 && *args != argv)
        *free_flag = 1;

    *stack_a = ft_createstack_a(*args);
    *stack_b = NULL;
}

int handle_memory_allocation_error(void *array, int free_flag, void *args)
{
    if (!array)
    {
        ft_printf("Error: Memory allocation failed\n");
        if (free_flag)
            free(args);
        return 1;
    }
    return 0;
}

void sort_stacks(t_nodes **stack_a, t_nodes **stack_b)
{
	t_moves moves;
	
    ft_sort3(stack_a);
    ft_lstprev(*stack_a);
    ft_lstprev(*stack_b);
    while (*stack_b != NULL)
    {
        moves.ra = 0;
        moves.rb = 0;
        moves.rra = 0;
        moves.rrb = 0;
        moves.totmoves = 0;
        target_distance(&moves, *stack_a, *stack_b);
        execute_rotations(&moves, stack_a, stack_b);
        pa(stack_a, stack_b);
        ft_putendl_fd("pa", 1);
    }
}

void populate_array(t_nodes *stack_a, int *array)
{
    t_nodes *current = stack_a;
    size_t i = 0;

    while (current != NULL)
    {
        array[i] = current->value;
        current = current->next;
        i++;
    }
}

void cleanup(int *array, char **args, int free_flag, t_nodes *stack_a, t_nodes *stack_b)
{
    free(array);
    if (free_flag)
        free_split(args);
    ft_lstclear_int(&stack_a);
    ft_lstclear_int(&stack_b);
}