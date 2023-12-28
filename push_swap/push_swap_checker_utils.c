/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:21:21 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/24 18:21:22 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp != NULL && tmp->nxt != NULL)
	{
		if (tmp->i > tmp->nxt->i)
			return (0);
		tmp = tmp->nxt;
	}
	return (-1);
}

void	print_res(t_data *d)
{
	if (is_sorted(d->a) == 0 || ps_lstsize(d->b) != 0)
		printf("KO\n");
	else
		printf("OK\n");
}

void	ps(t_data *d, char *cmd)
{
	char	*c;

	c = (char *) malloc (sizeof(char *) * ft_strlen(cmd));
	ft_strlcpy(c, cmd, ft_strlen(cmd));
	cmd_sp(d, c);
	if (d->flg == 1)
	{
		free(c);
		free(cmd);
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	free(c);
}

void	get_input(t_data *d)
{
	char	*cmd;

	cmd = get_next_line(0);
	if (cmd)
	{
		while (cmd)
		{
			ps(d, cmd);
			free(cmd);
			cmd = get_next_line(0);
		}
	}
	free(cmd);
	print_res(d);
}

