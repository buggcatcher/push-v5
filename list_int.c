/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:31:43 by mailinci          #+#    #+#             */
/*   Updated: 2024/08/24 12:35:39 by mailinci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodes	*ft_lstnew_int(int value)
{
	t_nodes	*new;

	new = malloc(sizeof(t_nodes));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	//printf("\nDEBUG: Created new node with value: %d\n", value);
	return (new);
}

t_nodes	*ft_lstnew_index(int index)
{
	t_nodes	*new;

	new = malloc(sizeof(t_nodes));
	if (!new)
		return (NULL);
	new->index = index;
	new->next = NULL;
	//printf("\nDEBUG: Created new node with value: %d\n", value);
	return (new);
}

t_nodes *ft_lstlast_int(t_nodes *lst)
{
    if (lst == NULL)
    {
        //printf("DEBUG: List is empty\n");
        return NULL;
    }

    while (lst->next)
        lst = lst->next;

    //printf("DEBUG: Last node value in the list: %d\n", lst->value);

    return lst;
}

void ft_lstadd_back_int(t_nodes **lst, t_nodes *new)
{
    t_nodes *tmp;

    if (!new)
        return;

    if (!*lst)
    {
        *lst = new;
        //printf("DEBUG: Added new node with value %d as the first node\n", new->value);
        return;
    }

    tmp = ft_lstlast_int(*lst);
    tmp->next = new;
    //printf("DEBUG: Added new node with value %d to the end of the list\n", new->value);
}
int ft_lstsize_int(t_nodes *lst)
{
    int size = 0;

    while (lst)
    {
        size++;
        lst = lst->next;
    }
    return size;
}

void ft_lstprev(t_nodes *head)
{
    t_nodes *current = head;
    t_nodes *previous = NULL;

    while (current != NULL)
    {
        current->prev = previous;
        previous = current;
        current = current->next;
    }
}
int ft_lstlast_index(t_nodes *head)
{
    t_nodes *current = head;

    if (current == NULL)
    {
        return -1; // empty list
    }

    while (current->next != NULL)
    {
        current = current->next;
    }
    return current->index;
}

t_nodes *ft_lstmin_index(t_nodes *stack)
{
    t_nodes *current = stack;
    t_nodes *min = stack;

    while (current != NULL)
    {
        if (current->index < min->index)
            min = current;
        current = current->next;
    }
    return min;
}