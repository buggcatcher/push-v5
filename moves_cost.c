/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:42:51 by mailinci          #+#    #+#             */
/*   Updated: 2024/08/05 21:43:14 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calculate_distance_to_top(t_stack *stack, int target_index, int *use_reverse)
{
    int distance_from_tail = 0;
    int distance_from_head = 0;
    t_nodes *current;

    current = stack->head;
    while (current && current->index != target_index)
    {
        distance_from_head++;
        current = current->next;
    }

    current = stack->tail;
    while (current && current->index != target_index)
    {
        distance_from_tail++;
        current = current->prev;
    }

    *use_reverse = 1;
    if (distance_from_tail <= distance_from_head)
        return distance_from_tail;
    *use_reverse = 0;
    return distance_from_head;
}
    /// ??? ///
    // while (step-- > 0)
    // {
    //     if (use_reverse)
    //         reverse_rotate(stack);    // crea delle fx che accettino sia a che b
    //     else
    //         rotate(stack);            // same shit
    // }

int find_target_index(t_nodes *stack_a, t_nodes *stack_b)
{
    t_nodes *node_a = stack_a;
    t_nodes *node_b = stack_b;
    int target_index = -1;

    if (node_b->index > node_a->index && node_b->index > node_a->next->index)
        target_index = node_a->next->index;
    else
        target_index = node_a->index;

    return target_index;
}

void assign_cost(t_moves *moves, t_stack *stack_a, t_stack *stack_b, int target_index)
{
    int array[6] = {0}; // Indexes: 0=ra, 1=rb, 2=rra, 3=rrb, 4=rr, 5=rrr
    int use_reverse;
    int distance;
    int i;

    for (i = 0; i < 6; i++)
    {   
        find_target_index(stack_a, stack_b);
        if (i == 0)
            distance = calculate_distance_to_top(stack_a, target_index, &use_reverse);
        else if (i == 1)

            distance = calculate_distance_to_top(stack_b, target_index, &use_reverse);
        else if (i == 2)
            distance = calculate_distance_to_top(stack_a, target_index, &use_reverse);
        else if (i == 3)
            distance = calculate_distance_to_top(stack_b, target_index, &use_reverse);
        array[i] = distance;
    }
    /// ??? ///
    // void cancel_out_rotations to assign rr and rrr (t_moves *moves, int size_a, int size_b)
    // {
    //     if (moves->ra > size_a / 2)
    //         moves->rra = size_a - moves->ra;
    //     if (moves->rb > size_b / 2)
    //         moves->rrb = size_b - moves->rb;
    //     moves->ra = moves->rra_after_push;
    // }

    moves->ra = array[0];
    moves->rb = array[1];
    moves->rra = array[2];
    moves->rrb = array[3];
    moves->rr = array[4];
    moves->rrr = array[5];
}
    /// ??? ///
    // choose_move
    // 1st case: il maggiore tra ra e rb
    // 2nd case: ra + rrb
    // 3rd case: rra + rb
    // 4th case: il maggiore tra rra e rrb

    // se 1st case e' il minore
    //     se ra > rb
    //         rr = rb
    //         ra = ra-rb
    //     altrimenti
    //         rr = ra
    //         rb = rb-ra
    // tutte le altre rotazioni sono 0