/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokhan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:29:34 by mokhan            #+#    #+#             */
/*   Updated: 2023/10/06 13:37:49 by mokhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flags_nbr(const char *param, int *flags)
{
	int	i;
	int	n;

	n = ft_atoi(param);
	i = ft_numlen(n, 10) - 1;
	if (flags[5])
		flags[6] = n;
	else
		flags[7] = n;
	return (i);
}

static int	*check_flags(const char *param, int *flags, int *k)
{
	int		j;
	char	*cflags;

	cflags = " +#-0.";
	j = 8;
	while (j)
		flags[--j] = 0;
	while (param[*k] && !ft_strchr("%csdixXup", param[*k]))
	{
		j = 0;
		while (cflags[j])
		{
			if (param[*k] == cflags[j])
				flags[j] = 1;
			j++;
		}
		if (param[*k] >= '1' && param[*k] <= '9')
			*k += flags_nbr(&param[*k], flags);
		(*k)++;
	}
	return (flags);
}

static int	check_conversion(const char param, va_list ap, int *flags)
{
	if (!(param))
		return (0);
	if (param == '%')
		return (write(1, "%", 1));
	if (param == 'c')
		return (print_chr(va_arg(ap, int), flags));
	if (param == 's')
		return (print_str(va_arg(ap, char *), flags));
	if (param == 'd' || param == 'i')
		return (print_nbr(va_arg(ap, int), flags));
	if (param == 'x' || param == 'X')
		return (print_hex(va_arg(ap, unsigned int), flags, param));
	if (param == 'u')
		return (print_unsigned(va_arg(ap, unsigned int), flags));
	if (param == 'p')
		return (print_pointer(va_arg(ap, unsigned long long), flags));
	return (0);
}

int	ft_printf(const char *param, ...)
{
	int		count;
	int		k;
	int		flags[8];
	va_list	ap;

	va_start(ap, param);
	count = 0;
	k = 0;
	while (param[k])
	{
		if (param[k] == '%' && param[k + 1])
		{
			k++;
			check_flags(param, flags, &k);
			count += check_conversion(param[k], ap, flags);
		}
		else
			count += write(1, &param[k], 1);
		k++;
	}
	va_end(ap);
	return (count);
}
