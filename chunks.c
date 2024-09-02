/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:55:21 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/01 12:46:04 by mailinci         ###   ########.fr       */
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
			ft_putendl_fd("pb", 1);
			pushed++;
		}
		else
		{
			ra(stack_a);
			ft_putendl_fd("ra", 1);
		}
		update_chunks(stack_b, &min_chunk, &step, &pushed);
	}
}

void	update_chunks(t_nodes **stack_b, int *min_chunk,
	int *step, int *pushed)
{ 	
	if (*stack_b && (*stack_b)->index && ft_lstsize_int(*stack_b) > 1
		&& (*stack_b)->index >= *min_chunk
		&& (*stack_b)->index < (*min_chunk + *step))
	{
		rb(stack_b);
		ft_putendl_fd("rb", 1);
	}
	if (*pushed == (*min_chunk + *step + *step - 1))
	{
		*min_chunk += (*step * 2);
		*step = (*step / 3) + (*step % 3);
	}
}


// divides into two chunks instead of three

// void divide_and_push(t_nodes **stack_a, t_nodes **stack_b) {
//     int count = ft_lstsize_int(*stack_a);
//     int mid = count / 2;

//     while (ft_lstsize_int(*stack_a) > 3) {
//         if ((*stack_a)->index < mid) {
//             pb(stack_a, stack_b);
//         } else {
//             pb(stack_a, stack_b);
//             rb(stack_b);
//         }
//     }
// }




