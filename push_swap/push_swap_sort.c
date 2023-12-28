/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:20:40 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/22 15:20:41 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_data *d)
{
	int	x;
	int	y;
	int	z;

	x = d->a->i;
	y = d->a->nxt->i;
	z = d->a->nxt->nxt->i;
	if (x > y && y < z && x < z)
		cmd_sp(d, "sa");
	else if (x > y && y > z && x > z)
	{
		cmd_sp(d, "sa");
		cmd_sp(d, "rra");
	}
	else if (x < y && y > z && x < z)
	{
		cmd_sp(d, "sa");
		cmd_sp(d, "ra");
	}
	else if (x > y && y < z && x > z)
		cmd_sp(d, "ra");
	else if (x < y && y > z && x > z)
		cmd_sp(d, "rra");
}

void	sort5(t_data *d)
{
	while (ps_lstsize(d->a) > 3)
		cmd_sp(d, "pb");
	sort3(d);
	if (d->size == 5)
	{
		if (d->b->i == 3 && d->b->nxt->i == 2)
			cmd_sp(d, "rr");
		else if (d->b->i == 3 && d->b->nxt->i == 4)
			cmd_sp(d, "rrr");
		else if (d->b->i == 3)
			cmd_sp(d, "sb");
	}
	while (d->b != NULL)
	{
		if (d->b->i == d->a->i - 1 || (d->b->i == ps_lstlast(d->a)->i + 1))
			cmd_sp(d, "pa");
		else if (d->b->i == d->a->nxt->i - 1)
			cmd_sp(d, "ra");
		else
			cmd_sp(d, "rra");
	}
}

int	get_min(t_stack *a)
{
	int		steps;
	t_stack	*tmp;

	steps = 0;
	tmp = a;
	while (tmp->i != ps_lstmin(tmp))
	{
		tmp = tmp->nxt;
		steps++;
	}
	return (steps);
}

void	do_sort(t_data *d)
{
	int	min;

	if (d->size == 2 && d->a->i > d->a->nxt->i)
		cmd_sp(d, "sa");
	else if (d->size <= 3)
		sort3(d);
	else if (d->size <= 5)
		sort5(d);
	else
	{
		pushb(d);
		sort3(d);
		pusha(d);
	}
	min = get_min(d->a);
	if (min <= ps_lstsize(d->a) / 2)
	{
		while (d->a->i != ps_lstmin(d->a))
			cmd_sp(d, "ra");
	}
	else
	{
		while (d->a->i != ps_lstmin(d->a))
			cmd_sp(d, "rra");
	}
}

