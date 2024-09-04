/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:42:51 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/03 12:53:50 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calculate_distance_from_head(t_nodes *stack, int target)
{
    int distance_from_head;
    t_nodes *current;

	distance_from_head = 0;
	current = stack;
    while (current && current->index != target)
    {
        distance_from_head++;
        current = current->next;
    }
     return (distance_from_head);
}


int find_target(t_nodes *stack_a, t_nodes *stack_b)
{
	int		target;
	t_nodes	*current_a;


	if (!stack_b)
		return (-1);
	current_a = stack_a;
	target = -1;
	if (current_a->index > stack_b->index)
		target = current_a->index;
	while (current_a)
	{
		if (current_a->index > stack_b->index && (target == -1 || current_a->index < target))
			target = current_a->index;
		current_a = current_a->next;
	}
	if (target != -1)
		return (target);
	current_a = ft_lstmin_index(stack_a);
	if (current_a)
		return (current_a->index);
	return (-1);
}


void update_lowest_cost(t_moves *moves, t_nodes *stack_b)
{
	t_nodes *min_moves_node;

	min_moves_node = stack_b;
	while (stack_b)
	{
		if (stack_b->moves.totmoves < min_moves_node->moves.totmoves)
			min_moves_node = stack_b;
		stack_b = stack_b->next;
	}
	*moves = min_moves_node->moves;
}


void target_distance(t_moves *moves, t_nodes *stack_a, t_nodes *stack_b)
{
	t_nodes	*stack_b_p;
    int		target_a;
	int		target_b;

	stack_b_p = stack_b;
	while (stack_b_p)
	{
		stack_b_p->moves.totmoves = 0;
		target_a = find_target(stack_a, stack_b_p);
		target_b = stack_b_p->index;
		stack_b_p->moves.ra = calculate_distance_from_head(stack_a, target_a);
		stack_b_p->moves.rb = calculate_distance_from_head(stack_b, target_b);
		stack_b_p->moves.rra = ft_lstsize_int(stack_a) - stack_b_p->moves.ra;
		stack_b_p->moves.rrb = ft_lstsize_int(stack_b) - stack_b_p->moves.rb;
		if (stack_b_p->moves.ra < stack_b_p->moves.rra)
			stack_b_p->moves.totmoves += stack_b_p->moves.ra;
		else
			stack_b_p->moves.totmoves += stack_b_p->moves.rra;
		if (stack_b_p->moves.rb < stack_b_p->moves.rrb)
			stack_b_p->moves.totmoves += stack_b_p->moves.rb;
		else
			stack_b_p->moves.totmoves += stack_b_p->moves.rrb;
		stack_b_p = stack_b_p->next;
	}
	update_lowest_cost(moves, stack_b);
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




// t_moves assign_cost(t_moves moves)
// {
//     t_moves cost = moves;

//     // Caso 1: ra > rb
//     if (moves.ra > moves.rb)
//     {
//         cost.rr = moves.rb;
//         cost.ra = moves.ra - moves.rb;
//         cost.rb = 0;
//         cost.rra = 0;
//         cost.rrb = 0;
//         cost.rrr = 0;
//     }
//     // Caso 2: ra + rrb
//     else if (moves.rra + moves.rb > moves.ra + moves.rrb)

//     {
//         cost.rr = 0;
//         cost.rrr = 0;
//         cost.rra = 0;
//         cost.rb = 0;
//         cost.ra = moves.ra + moves.rrb;
//         cost.rrb = 0;
//     }
//     // Caso 3: rra + rb
//     else if (moves.rra + moves.rb < moves.ra + moves.rrb)
//     {
//         cost.rr = 0;
//         cost.rrr = 0;
//         cost.ra = 0;
//         cost.rrb = 0;
//         cost.rra = moves.rra + moves.rb;
//         cost.rb = 0;
//     }
//     // Caso 4: rra > rrb
//     else if (moves.rra > moves.rrb)
//     {
//         cost.rrr = moves.rrb;
//         cost.rra = moves.rra - moves.rrb;
//         cost.rrb = 0;
//         cost.ra = 0;
//         cost.rb = 0;
//         cost.rr = 0;
//     }
//     print_moves_cost(cost);
//     return (cost); //ritorno il costo come struct
// }
