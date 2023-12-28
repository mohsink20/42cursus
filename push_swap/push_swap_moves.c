/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:52:20 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/20 19:52:21 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->nxt == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->nxt;
	tmp->nxt = (*stack)->nxt;
	(*stack)->nxt = tmp;
}

void	ps_push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	*b = (*b)->nxt;
	tmp->nxt = *a;
	*a = tmp;
}

void	ps_rotate(t_stack **stack)
{
	t_stack	*start;
	t_stack	*new;

	if (*stack == NULL || (*stack)->nxt == NULL)
		return ;
	start = *stack;
	while ((*stack)->nxt != NULL)
	{
		*stack = (*stack)->nxt;
	}
	(*stack)->nxt = start;
	new = start->nxt;
	start->nxt = NULL;
	*stack = new;
}

void	ps_rrotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;

	if (*stack == NULL || (*stack)->nxt == NULL)
		return ;
	tmp = *stack;
	while (tmp->nxt != NULL)
	{
		end = tmp ;
		tmp = tmp->nxt;
	}
	tmp->nxt = *stack;
	*stack = tmp;
	end->nxt = NULL;
}
