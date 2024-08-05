/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:55:21 by mailinci          #+#    #+#             */
/*   Updated: 2024/08/04 17:21:46 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int make_chunks(int stack_size)
{
    int chunk_size;

    chunk_size = 1;
    if ((stack_size - chunk_size) > 0 && (stack_size - chunk_size) < 4)
        chunk_size = 2;
    else
        chunk_size = stack_size / 3;
    return chunk_size;
}

void	push_chunks(t_nodes	**stack_a, t_nodes **stack_b, int count)
{
	int	min_chunk;
	int	step;
	int	pushed;

	min_chunk = 1;
	pushed = 0;
	step = make_chunks(count);
	while (pushed < (count - 3) && !ft_order_check(*stack_a))
	{
		//printf("DEBUG index: %d\tvalue: %d\n", (*stack_a)->index, (*stack_a)->value);
		if ((*stack_a)->index >= min_chunk
			&& ((*stack_a)->index) < (min_chunk + step + step)
			&& (*stack_a)->index <= (count - 3))
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		update_chunks(stack_b, &min_chunk, &step, &pushed);
	}
}

void	update_chunks(t_nodes **stack_b, int *min_chunk,
	int *step, int *pushed)
{ 	
	if (*stack_b && (*stack_b)->index && ft_lstsize_int(*stack_b) > 1
		&& (*stack_b)->index >= *min_chunk
		&& (*stack_b)->index < (*min_chunk + *step))
		rb(stack_b);
	if (*pushed == (*min_chunk + *step + *step - 1))
	{
		*min_chunk += (*step * 2);
		*step = (*step / 3) + (*step % 3);
	}
}






