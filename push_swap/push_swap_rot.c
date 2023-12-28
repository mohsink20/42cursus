/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:20:05 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/22 15:20:08 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case1(t_data *d, t_step s)
{
	int	i;

	i = 0;
	while (i < s.a && i < s.b)
	{
		cmd_sp(d, "rr");
		i++;
	}
	while (i < s.a)
	{
		cmd_sp(d, "ra");
		i++;
	}
	while (i < s.b)
	{
		cmd_sp(d, "rb");
		i++;
	}
}

void	case2(t_data *d, t_step s)
{
	int	i;

	i = 0;
	while (i < ps_lstsize(d->a) - s.a && i < ps_lstsize(d->b) - s.b)
	{
		cmd_sp(d, "rrr");
		i++;
	}
	while (i < ps_lstsize(d->a) - s.a)
	{
		cmd_sp(d, "rra");
		i++;
	}
	while (i < ps_lstsize(d->b) - s.b)
	{
		cmd_sp(d, "rrb");
		i++;
	}
}

void	case3(t_data *d, t_step s)
{
	int	i;

	i = 0;
	while (i < s.a)
	{
		cmd_sp(d, "ra");
		i++;
	}
	i = 0;
	while (i < ps_lstsize(d->b) - s.b)
	{
		cmd_sp(d, "rrb");
		i++;
	}
}

void	case4(t_data *d, t_step s)
{
	int	i;

	i = 0;
	while (i < ps_lstsize(d->a) - s.a)
	{
		cmd_sp(d, "rra");
		i++;
	}
	i = 0;
	while (i < s.b)
	{
		cmd_sp(d, "rb");
		i++;
	}
}

void	rotate_sort(t_data *d, t_step s)
{
	if (d->mini.rot == 1)
		case1(d, s);
	else if (d->mini.rot == 2)
		case2(d, s);
	else if (d->mini.rot == 3)
		case3(d, s);
	else if (d->mini.rot == 4)
		case4(d, s);
}
