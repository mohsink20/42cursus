/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:20:48 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/22 15:20:49 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_stack(int max, t_stack *a)
{
	if (a == NULL || a->nxt == NULL)
		return (-1);
	while (a != NULL)
	{
		if (a->i < max)
		{
			return (0);
		}
		a = a->nxt;
	}
	return (-1);
}

void	move_half(t_data *d)
{
	while (max_stack(d->size / 2, d->a) == 0)
	{
		if (d->a->i < d->size / 2 && d->a->i >= d->size / 4)
			cmd_sp(d, "pb");
		else if (d->a->i < d->size / 4)
		{
			cmd_sp(d, "pb");
			cmd_sp(d, "rb");
		}
		else
			cmd_sp(d, "ra");
	}
}

void	pushb(t_data *d)
{
	int	x;
	int	y;

	x = d->size / 11;
	y = d->size / 2 + (x * 2);
	move_half(d);
	while (y <= d->size && ps_lstsize(d->a) > 3)
	{
		if (d->a->i <= y)
			cmd_sp(d, "pb");
		else
			cmd_sp(d, "ra");
		if (max_stack(y, d->a) != 0 && d->size >= 12)
			y += (x * 2);
		if (max_stack(y, d->a) != 0 && d->size < 12)
			y += 2;
	}
	while (y > d->size && ps_lstsize(d->a) > 3)
		cmd_sp(d, "pb");
}

void	pusha(t_data *d)
{
	int	i;

	i = 3;
	while (ps_lstsize(d->b) >= d->size / 2)
	{
		evaluate_steps(d, (d->size / 4) * i);
		rotate_sort(d, d->mini);
		cmd_sp(d, "pa");
		if ((d->size / 4) * i <= ps_lstsize(d->b))
			i--;
	}
	while (d->b != NULL)
	{
		evaluate_steps(d, 0);
		rotate_sort(d, d->mini);
		cmd_sp(d, "pa");
	}
}
