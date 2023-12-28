/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:20:32 by mokhan            #+#    #+#             */
/*   Updated: 2023/12/22 15:20:33 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numeric(const char *str)
{
	if (*str == '-')
	{
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	indexing(int num, int *n, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (n[i] <= num)
			j++;
		i++;
	}
	return (j);
}

int	validate(int i, char **av)
{
	int		j;
	long	k;

	j = 0;
	while (av[i][j])
	{
		if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-')
			return (-1);
		j++;
	}
	if (!is_numeric(av[i]) || (av[i][0] == '-' && av[i][1] == '\0'))
		return (-1);
	j = 0;
	while (j < i)
	{
		if (ft_strlen(av[j]) == ft_strlen(av[i])
			&& ft_strncmp(av[i], av[j], ft_strlen(av[i])) == 0)
			return (-1);
		j++;
	}
	k = atoi_long(av[i]);
	if (k > 2147483647 || k < -2147483647)
		return (-1);
	return (0);
}

t_stack	*init_list(t_data *d, t_stack *a, int *num)
{
	t_stack	*new;
	int		i;
	int		j;

	i = 0;
	while (i < d->size)
	{
		j = indexing(num[i], num, d->size);
		new = ps_lstnew(num[i], j);
		if (!new)
			ft_error();
		ps_lstadd_back(&a, new);
		i++;
	}
	return (a);
}

t_stack	*init_stack(t_data *d, int size, char **av, int add)
{
	t_stack	*a;
	int		i;
	int		*num;

	i = 0;
	a = NULL;
	num = (int *)malloc(sizeof(int) * size);
	d->size = size;
	d->chker = 0;
	while (i < size)
	{
		if (validate(i + add, av) != 0)
		{
			if (add == 0)
				ft_free((void **)av);
			free(num);
			ft_error();
		}
		num[i] = ft_atoi(av[i + add]);
		i++;
	}
	a = init_list(d, a, num);
	free(num);
	return (a);
}
