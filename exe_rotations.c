/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:57:32 by mailinci          #+#    #+#             */
/*   Updated: 2024/08/27 15:59:25 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void execute_rotations(t_moves *moves, t_nodes **stack_a, t_nodes **stack_b)
{
	if (moves->ra < moves->rra)
	{
		while (moves->ra > 0 && moves->rb > 0 && moves->rb < moves->rrb)
		{
			rr(stack_a, stack_b);
			moves->ra--;
			moves->rb--;
		}
		while (moves->ra > 0)
		{
			ra(stack_a);
			moves->ra--;
		}
	}
	else
	{
		while (moves->rra > 0 && moves->rrb > 0 && moves->rrb < moves->rb)
		{
			rrr(stack_a, stack_b);
			moves->rra--;
			moves->rrb--;
		}
		while (moves->rra > 0)
		{
			rra(stack_a);
			moves->rra--;
		}
	}
	if (moves->rb <= moves->rrb)
	{
		while (moves->rb > 0)
		{
			rb(stack_b);
			moves->rb--;
		}
	}
	else
	{
		while (moves->rrb > 0)
		{
			rrb(stack_b);
			moves->rrb--;
		}
	}
	//print_moves_cost(*moves);
}
void rotate_to_min(t_nodes **stack_a)
{
	int min_index;
	int distance_from_head;
	t_nodes *current;

	min_index = find_min_index(*stack_a);
	distance_from_head = calculate_distance_from_head(*stack_a, min_index);
	current = *stack_a;
	if (distance_from_head > ft_lstsize_int(*stack_a) / 2)
	{
		while (current->index != min_index)
		{
			rra(stack_a);
			current = *stack_a;
		}
	}
	else
	{
		while (current->index != min_index)
		{
			ra(stack_a);
			current = *stack_a;
		}
	}
}

int find_min_index(t_nodes *stack)
{
	int min_index;
	t_nodes *current;

	min_index = stack->index;
	current = stack;
	while (current)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	return min_index;
}

int check_order(t_nodes *stack)
{
	t_nodes *current;

	current = stack;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}