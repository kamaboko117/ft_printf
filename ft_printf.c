/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:54:47 by asaboure          #+#    #+#             */
/*   Updated: 2020/05/08 00:58:10 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

#include <stdio.h>

int		ft_printf(const char *form, ...)
{
	int		(**f)(va_list *, const char *);
	va_list	list;
	int		i;
	int		tmp;
	int		len;

	f = tabinit();
	i = 0;
	len = 0;
	va_start(list, form);
	while (form[i])
	{
		tmp = 0;
		if (i != 0 && form[i - 1] == '%' && form[i] != '%')
		{
			if ((tmp = find_index(form[i])) != -1)
				len += (*f[tmp])(&list, form + i) - 2;
		}
		else if (form[i] != '%' || (form[i - 1] == '%' && form[i] == '%'))
			write(1, &form[i], 1);
		while ((tmp >= 8 && tmp <= 10) && ((form[i] >= '0' && form[i] <= '9') || form[i] == '-' || form[i] == '.' || form[i] == '*'))
			i++;
		i++;
	}
	len += i;
	return (len);
}
