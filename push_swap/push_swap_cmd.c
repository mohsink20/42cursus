/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:53:49 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/20 22:54:04 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_rot(t_data *d, char *c)
{
	d->flg = 0;
	if (ps_strcmp(c, "rra", ft_strlen(c)) == 0)
		ps_rrotate(&d->a);
	else if (ps_strcmp(c, "rrb", ft_strlen(c)) == 0)
		ps_rrotate(&d->b);
	else if (ps_strcmp(c, "rrr", ft_strlen(c)) == 0)
	{
		ps_rrotate(&d->a);
		ps_rrotate(&d->b);
	}
	else if (ps_strcmp(c, "ra", ft_strlen(c)) == 0)
		ps_rotate(&d->a);
	else if (ps_strcmp(c, "rb", ft_strlen(c)) == 0)
		ps_rotate(&d->b);
	else if (ps_strcmp(c, "rr", ft_strlen(c)) == 0)
	{
		ps_rotate(&d->a);
		ps_rotate(&d->b);
	}
	else
		d->flg = 1;
}

void	cmd_sp(t_data *d, char *c)
{
	d->flg = 0;
	if (ps_strcmp(c, "sa", ft_strlen(c)) == 0)
		ps_swap(&d->a);
	else if (ps_strcmp(c, "sb", ft_strlen(c)) == 0)
		ps_swap(&d->b);
	else if (ps_strcmp(c, "ss", ft_strlen(c)) == 0)
	{
		ps_swap(&d->a);
		ps_swap(&d->b);
	}
	else if (ps_strcmp(c, "pa", ft_strlen(c)) == 0)
		ps_push(&d->a, &d->b);
	else if (ps_strcmp(c, "pb", ft_strlen(c)) == 0)
		ps_push(&d->b, &d->a);
	else
		cmd_rot(d, c);
	if (d->flg == 0 && d->chker == 0)
		printf("%s\n", c);
}
