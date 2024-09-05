/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mailinci <mailinci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:31:43 by mailinci          #+#    #+#             */
/*   Updated: 2024/09/05 23:44:39 by mailinci         ###   ########.fr       */
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
	return (new);
}

t_nodes *ft_lstlast_int(t_nodes *lst)
{
    if (lst == NULL)
    {
        return NULL;
    }
    while (lst->next)
        lst = lst->next;
    return (lst);
}

void ft_lstadd_back_int(t_nodes **lst, t_nodes *new)
{
    t_nodes *tmp;

    if (!new)
        return;

    if (!*lst)
    {
        *lst = new;
        return;
    }

    tmp = ft_lstlast_int(*lst);
    tmp->next = new;
}
int ft_lstsize_int(t_nodes *lst)
{
    int size = 0;

    while (lst)
    {
        size++;
        lst = lst->next;
    }
    return (size);
}

void ft_lstprev(t_nodes *head)
{
    t_nodes *current;
    t_nodes *previous;

    current = head;
    previous = NULL;
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
        return -1;
    }
    while (current->next != NULL)
    {
        current = current->next;
    }
    return (current->index);
}

t_nodes *ft_lstmin_index(t_nodes *stack)
{
    t_nodes *current;
    t_nodes *min;

    current = stack;
    min = stack;
    while (current != NULL)
    {
        if (current->index < min->index)
            min = current;
        current = current->next;
    }
    return (min);
}

void ft_lstclear_int(t_nodes **lst)
{
    t_nodes *current;
    t_nodes *next;

    current = *lst;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *lst = NULL;
}

void free_split(char **split)
{
    int i;

    if (!split)
        return;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}