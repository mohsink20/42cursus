/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_smallest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:34:48 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/22 15:34:49 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_step	ps_least(t_data *d, int a, int b, t_step cur)
{
	if (a <= ps_lstsize(d->a) / 2 && b <= ps_lstsize(d->b) / 2)
	{
		if (a >= b)
			cur.least = a;
		else
			cur.least = b;
		cur.rot = 1;
	}
	else if (a > ps_lstsize(d->a) / 2 && b > ps_lstsize(d->b) / 2)
	{
		if ((ps_lstsize(d->a) - a) >= (ps_lstsize(d->b) - b))
			cur.least = (ps_lstsize(d->a) - a);
		else
			cur.least = (ps_lstsize(d->b) - b);
		cur.rot = 2;
	}
	else
		cur = ps_least2(d, a, b, cur);
	return (cur);
}

t_step	ps_least2(t_data *d, int a, int b, t_step cur)
{
	if (a <= ps_lstsize(d->a) / 2 && b > ps_lstsize(d->b) / 2)
	{
		cur.least = a + (ps_lstsize(d->b) - b);
		cur.rot = 3;
	}
	else if (a > ps_lstsize(d->a) / 2 && b <= ps_lstsize(d->b) / 2)
	{
		cur.least = b + (ps_lstsize(d->a) - a);
		cur.rot = 4;
	}
	return (cur);
}
