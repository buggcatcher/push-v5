/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:42:51 by mailinci          #+#    #+#             */
/*   Updated: 2024/08/19 17:01:10 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calculate_distance_from_head(t_nodes *stack, int target)
{
    int distance_from_head = 0;
    t_nodes *current;

    current = stack->head;
    while (current && current->index != target)
    {
        distance_from_head++;
        current = current->next;
    }

    return distance_from_head;
}

int find_target(t_nodes *stack_a, t_nodes *stack_b)
{
    t_nodes *node_a = stack_a->head;
    t_nodes *node_b = stack_b->head;
    int counter;

    counter = 0;
    printf("\nDEBUG: node_b->index: %d\n", node_b->next->index);
    while (1)
    {
        if (counter == ft_lstsize_int(stack_a))
        {
            if (node_b->index > node_a->index && node_b->index > stack_a->head->index)
                return (stack_a->head->index);

            else
                return (-1);
        }
        else
        {
            if (node_b->index > node_a->index && node_b->index > node_a->next->index)
                return (node_a->next->index);
            else
                node_a = node_a->next;
        }
        counter++;
    }
    return (-1); // non dovrebbe mai accadere
}

void target_distance(t_moves *moves, t_nodes *stack_a, t_nodes *stack_b)
{
    moves->ra = calculate_distance_from_head(stack_a->head, find_target(stack_a, stack_b));
    moves->rb = calculate_distance_from_head(stack_b->head, find_target(stack_b, stack_a));
    moves->rra = ft_lstsize_int(stack_a) - moves->ra;
    moves->rrb = ft_lstsize_int(stack_b) - moves->rb;
}

t_moves assign_cost(t_moves moves)
{
    t_moves cost = moves;

    // Caso 1: ra > rb
    if (moves.ra > moves.rb)
    {
        cost.rr = moves.rb;
        cost.ra = moves.ra - moves.rb;
        cost.rb = 0;
        cost.rra = 0;
        cost.rrb = 0;
        cost.rrr = 0;
    }
    // Caso 2: ra + rrb
    else if (moves.rra + moves.rb > moves.ra + moves.rrb)

    {
        cost.rr = 0;
        cost.rrr = 0;
        cost.rra = 0;
        cost.rb = 0;
        cost.ra = moves.ra + moves.rrb;
        cost.rrb = 0;
    }
    // Caso 3: rra + rb
    else if (moves.rra + moves.rb < moves.ra + moves.rrb)
    {
        cost.rr = 0;
        cost.rrr = 0;
        cost.ra = 0;
        cost.rrb = 0;
        cost.rra = moves.rra + moves.rb;
        cost.rb = 0;
    }
    // Caso 4: rra > rrb
    else if (moves.rra > moves.rrb)
    {
        cost.rrr = moves.rrb;
        cost.rra = moves.rra - moves.rrb;
        cost.rrb = 0;
        cost.ra = 0;
        cost.rb = 0;
        cost.rr = 0;
    }
    return (cost); //ritorno il costo come struct
}


// s_moves min_moves;

// while(node_b)
// {
//     moves = numero_mosse(node_b);
//     if (tot_moves(moves) < min_moves)
//     {
//         min_moves = moves;  // mosse da fare per spostarlo
//         best_node = node_b; //nodo da spostare
//     }
//     node_b = node_b->next;
// }


// typedef void (*move_fxs)();

// void execute_moves(t_moves moves)
// {
//     move_fxs fxs[] = {ra, rb, rra, rrb, rr, rrr};
//     int* cost[] = {&moves.ra, &moves.rb, &moves.rra, &moves.rrb, &moves.rr, &moves.rrr};
//     int i = 0;

//     while (i < 6)
//     {
//         while (*cost[i] > 0)
//         {
//             fxs[i]();
//             (*cost[i])--;
//         }
//         i++;
//     }
// }





/////////////////////
// versione estesa //
/////////////////////
// void esegui_moves(s_moves moves)
// {
//     while(moves.ra > 0)
//     {
//         ra();
//         moves.ra--;
//     }
//     while(moves.rb > 0)
//     {
//         rb();
//         moves.rb--;
//     }
//     while(moves.rra > 0)
//     {
//         rra();
//         moves.rra--;
//     }
//     while(moves.rrb > 0)
//     {
//         rrb();
//         moves.rrb--;
//     }
//     while(moves.rr > 0)
//     {
//         rr();
//         moves.rr--;
//     }
//     while(moves.rrr > 0)
//     {
//         rrr();
//         moves.rrr--;
//     }
// }

