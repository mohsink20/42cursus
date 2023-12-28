/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:19:40 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/22 15:19:41 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->nxt != NULL)
		lst = lst ->nxt;
	return (lst);
}

t_stack	*ps_lstnew(int n, int i)
{
	t_stack	*new;

	new = (t_stack *) malloc (sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = n;
	new->i = i;
	new->nxt = NULL;
	return (new);
}

int	ps_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->nxt;
		i++;
	}
	return (i);
}

void	ps_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	last = ps_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->nxt = new;
}

void	ps_lstclear(t_stack **head)
{
	t_stack	*current;
	t_stack	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->nxt;
		free(current);
		current = next;
	}
	*head = NULL;
}
