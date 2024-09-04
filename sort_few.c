/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:57:55 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/04 16:54:17 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
int ft_sort2(t_nodes **stack_a)
{
    if ((*stack_a)->value > (*stack_a)->next->value)
    {
        sa(stack_a);
        ft_putendl_fd("sa", 1);
    }
    return (0);
}

void ft_sort3(t_nodes **stack_a)
{
    int first;
    int second;
    int third;

    if (ft_lstsize_int(*stack_a) != 3)
        return;

    first = (*stack_a)->index;
    second = (*stack_a)->next->index;
    third = (*stack_a)->next->next->index;

    if (first > second && second < third && third > first)
        sort_case_1(stack_a);
    else if (first > second && second > third && third < first)
        sort_case_2(stack_a);
    else if (first > second && second < third && third < first)
        sort_case_3(stack_a);
    else if (first < second && second > third && third > first)
        sort_case_4(stack_a);
    else if (first < second && second > third && third < first)
        sort_case_5(stack_a);
}

void process_stack(int *array, int free_flag, char *args, t_nodes *stack_a, int **temp_array)
{
    int len;
    int *sorted_array;

    handle_memory_allocation_error(array, free_flag, args);
    populate_array(stack_a, array);
    len = ft_create_temp_array(stack_a, temp_array);
    sorted_array = sort_temp_array(*temp_array, len);
    if (temp_array == NULL)
    {
        ft_printf("ERROR: sort_temp_array failed\n");
        return ;
    }
    cold_start(*temp_array, &stack_a, len);
    assign_indices(stack_a, *temp_array, len);
    free(*temp_array);
    free(sorted_array);
}

