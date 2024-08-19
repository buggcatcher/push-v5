/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 17:52:26 by mailinci          #+#    #+#             */
/*   Updated: 2024/08/19 16:42:42 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodes	*ft_createstack_a(char **args)
{
	t_nodes	*stack_a;
	t_nodes	*value;
	int		num; //nel caso di zero non crea il primo nodo
	int		i;

	stack_a = NULL;
	i = 0;
	while (args[i] != NULL)
	{
        num = ft_atoi_minmax(args[i]);
        //printf("DEBUG: Processing value: %d\n", num);
		value = ft_lstnew_int(num);
        //printf("DEBUG: Adding value: %d\n\n", num);
		ft_lstadd_back_int(&stack_a, value);
		i++;
	}
	return (stack_a);
}

void	ft_print_nodes(t_nodes *stack)
{
	t_nodes *current = stack;
	while (current)
	{
		printf("[%d] -> ", current->value);
		current = current->next;
	}
	printf("[NULL]\n");
}


int     ft_create_temp_array(t_nodes *stack, int **array)
{
    int len = ft_lstsize_int(stack);
	t_nodes *current = stack;
    int i = 0;

    *array = malloc(sizeof(int) * len);
	while (current)
	{
		(*array)[i++] = current->value;
		current = current->next;
	}
    return (i);
}

void ft_print_indices_and_values(t_nodes *stack)
{
    t_nodes *current = stack;

    while (current != NULL)
    {
        printf("index: %d \t value: %d\n", current->index, current->value);
        current = current->next;
    }
}
void print_moves_cost(t_moves moves)
{
    printf("Cost of moves:\n");
    printf("ra: %d\n", moves.ra);
    printf("rb: %d\n", moves.rb);
    printf("rra: %d\n", moves.rra);
    printf("rrb: %d\n", moves.rrb);
    printf("rr: %d\n", moves.rr);
    printf("rrr: %d\n", moves.rrr);
}


int	main(int argc, char **argv)
{
    t_nodes *stack_a = NULL;
    t_nodes *stack_b = NULL;
    char **args;
    int free_flag;
    int *temp_array = NULL;
    int len = 0;
    int stack_size = ft_lstsize_int(stack_a);
    int *array = NULL;
    int i;
    int chunk_size = 0;
    
    free_flag = 0;
    args = ft_arg_checker(argc, argv);

    if (argc == 2 && args != argv)
        free_flag = 1;

    stack_a = ft_createstack_a(args);
    stack_b = NULL;

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
        return (1);
    }

 
    stack_size = ft_lstsize_int(stack_a);
    array = malloc(sizeof(int) * stack_size);
    if (!array)
    {
        ft_printf("Error: Memory allocation failed\n");
        if (free_flag)
            free(args);
        return (1);
    }
    
    t_nodes *current = stack_a;
    for (i = 0; current != NULL; i++)
    {
        array[i] = current->value;
        current = current->next;
    }

    // printf("\nstack_a\n");
	// ft_print_nodes(stack_a); 
    // printf("\nstack_b\n");
    // ft_print_nodes(stack_b);
    len = ft_create_temp_array(stack_a, &temp_array);
    cold_start(temp_array, &stack_a, len);
    ft_sort_temp_array(temp_array, len);
    //ft_print_temp_array(temp_array, len);
    ft_assign_indices(stack_a, temp_array, len);
    //ft_print_indices_and_values(stack_a);
    printf("\n");
    chunk_size = make_chunks(stack_size);
    push_chunks(&stack_a, &stack_b, stack_size);

    printf("\nstack_a\n");
	ft_print_nodes(stack_a);
    ft_print_indices_and_values(stack_a);
    printf("\nstack_b\n");
    ft_print_nodes(stack_b);
    ft_print_indices_and_values(stack_b);

    t_moves moves = {0, 0, 0, 0, 0, 0};
    target_distance(&moves, stack_a, stack_b);
    assign_cost(moves);
    print_moves_cost(moves);
    //exit(1);

    // start pushing to a according to the cost of the moves
    // while (stack_b != NULL)
    // {   
    //     t_moves cost;
    //     while(node_b)
    //     {
    //     cost = assign_distance(*moves, *stack_a, *stack_b)
    //     moves = numero_mosse(node_b);
    //     if (tot_moves(moves) < min_moves)
    //     {
    //         min_moves = moves;  // mosse da fare per spostarlo
    //         best_node = node_b; //nodo da spostare
    //     }
    //     node_b = node_b->next;
    // }
    //     choose_move(cost);
    //     execute_moves(min_moves);
    // }
    // ft_rotate_to_min



    free(array);
    if (free_flag)
        free(args);
    if (temp_array)
        free(temp_array);

    return 0;
}
