/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:17:08 by mailinci          #+#    #+#             */
/*   Updated: 2024/08/27 16:00:09 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int totmoves;
} t_moves;

typedef struct s_nodes 
{
	int 			value;
	int				index;
	int				*content;
	struct s_nodes	*next;
	struct s_nodes	*prev;
	t_moves			moves;
}	t_nodes;


void			execute_rotations(t_moves *moves, t_nodes **stack_a, t_nodes **stack_b);
void			rotate_to_min(t_nodes **stack_a);
int 			find_min_index(t_nodes *stack);
int				check_order(t_nodes *stack);

int				calculate_distance_from_head(t_nodes *stack, int target);
int				find_target(t_nodes *stack_a, t_nodes *stack_b);
void			target_distance(t_moves *moves, t_nodes *stack_a, t_nodes *stack_b);
t_moves			assign_cost(t_moves moves);
int 			find_cheapest_move(t_moves *moves);
void 			execute_cheapest_move(t_moves *moves, t_nodes **stack_a, t_nodes **stack_b);
void 			execute_moves(t_moves *moves, t_nodes **stack_a, t_nodes **stack_b);
int				find_min_index(t_nodes *stack);
int 			is_min_index_on_top(t_nodes *stack);
void			print_moves_cost(t_moves moves);

int				make_chunks(int count);
void			push_chunks(t_nodes **stack_a, t_nodes **stack_b, int count);
void			update_chunks(t_nodes **stack_b, int *min_chunk, int *step, int *pushed);

void            fill_left(int arr[], int temp_left[], int left, int low);
void	        fill_right(int arr[], int temp_right[], int right, int middle);
int	            create_arrays(int left, int right, int **temp_left, int **temp_right);
int	        	cold_start(int arr[], t_nodes **list_a, int length);
void			merge_sort(int arr[], int length);
void			merge_sort_recursion(int arr[], int low, int high);
void			merge_sorted_arrays(int arr[], int low, int middle, int high);
int				binary_search(int arr[], int target, int low, int high);
int				*ft_sort_temp_array(int arr[], int length);
void			ft_print_array(int arr[], int length);
void			ft_assign_indices(t_nodes *stack_a, int *sorted_array, int length);
void			ft_print_indices_and_values(t_nodes *stack_a);

int             ft_sort2(t_nodes **stack_a);
void            ft_sort3(t_nodes **stack_a);
int             ft_push_cost(t_nodes *node_b);
void            exe_cheapest_move(t_nodes **stack_a, t_nodes **stack_b);
t_nodes         *ft_find_min_node(t_nodes *stack_a);
void            ft_rotate_to_min(t_nodes **stack_a);
void	        ft_print_nodes(t_nodes *stack);
void			apply_moves(t_nodes *cheapest_node, t_nodes **stack_a, t_nodes **stack_b);

void			handle_error(const char *message);
int				parse_sign(const char *str, int *index);
unsigned long	parse_number(const char *str, int *index);
int				ft_atoi_minmax(const char *str);

int	            ft_isdup(int num, char **argv, int i);
int				ft_order_check(t_nodes *stack);
char			**ft_usage_check(int argc, char **argv);
char			**ft_arg_checker(int argc, char **argv);

t_nodes			*ft_createstack_a(char **args);
t_nodes         *ft_lstnew_int(int value);
t_nodes         *ft_lstlast_int(t_nodes *lst);
void            ft_lstadd_back_int(t_nodes **lst, t_nodes *new);
int             ft_lstsize_int(t_nodes *lst);
t_nodes			*ft_lstnew_index(int index);
void			ft_lstprev(t_nodes *head);
int				ft_lstlast_index(t_nodes *head);
t_nodes			*ft_lstmin_index(t_nodes *stack);

int				sa(t_nodes **stack_a);
int				sb(t_nodes **stack_b);
int				ss(t_nodes **stack_a, t_nodes **stack_b);

int	            push(t_nodes **stack_to, t_nodes **stack_from);
int				pa(t_nodes **stack_a, t_nodes **stack_b);
int				pb(t_nodes **stack_b, t_nodes **stack_a);

void			ra(t_nodes **stack_a);
void			rb(t_nodes **stack_b);
void			rr(t_nodes **stack_a, t_nodes **stack_b);

void			rra(t_nodes **stack_a);
void			rrb(t_nodes **stack_b);
void			rrr(t_nodes **stack_a, t_nodes **stack_b);

#endif