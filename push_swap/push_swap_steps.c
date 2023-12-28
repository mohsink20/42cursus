/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:20:18 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/22 15:20:20 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insert_steps(int val, t_stack *tmp_a)
{
	t_stack	*last;
	int		steps;

	steps = 0;
	last = ps_lstlast(tmp_a);
	while (tmp_a != NULL && ((tmp_a->i < val && last-> i > val)
			|| (tmp_a->i > val && last->i > val)
			|| (tmp_a->i < val && last->i < val)
			|| last->i > tmp_a->i))
	{
		last = tmp_a;
		tmp_a = tmp_a->nxt;
		steps++;
	}
	return (steps);
}

int	target_steps(int val, t_stack *a)
{
	t_stack	*tmp_a;
	int		steps;

	tmp_a = a;
	steps = 0;
	if (tmp_a != NULL && (val > ps_lstmax(a) || val < ps_lstmin(a)))
	{
		while (tmp_a->i != ps_lstmin(a))
		{
			steps++;
			tmp_a = tmp_a->nxt;
		}
	}
	else if (tmp_a != NULL)
		steps = insert_steps(val, tmp_a);
	return (steps);
}

t_step	optimal_steps(t_data *d, int b_steps, t_stack *tmp_b)
{
	t_step	cur;
	int		a_steps;

	a_steps = 0;
	cur.b = b_steps;
	a_steps = target_steps(tmp_b->i, d->a);
	cur.a = a_steps;
	cur = ps_least(d, a_steps, b_steps, cur);
	b_steps++;
	return (cur);
}

void	evaluate_steps(t_data *d, int max)
{
	t_stack	*tmp_b;
	t_step	cur;
	int		steps;

	tmp_b = d->b;
	steps = 0;
	d->mini.least = 2147483647;
	while (tmp_b != NULL)
	{
		if (tmp_b->i >= max)
			cur = optimal_steps(d, steps, tmp_b);
		if (cur.least < d->mini.least)
			d->mini = cur;
		tmp_b = tmp_b->nxt;
		steps++;
	}
}
