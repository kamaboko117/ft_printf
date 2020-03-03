/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:54:47 by asaboure          #+#    #+#             */
/*   Updated: 2020/03/03 19:22:22 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

#include <stdio.h>

int		ft_printf(const char *form, ...)
{
	void	(**f)(va_list *, const char *);
	va_list	list;
	int		i;
	int		tmp;

	f = tabinit();
	tmp = 0;
	i = 0;
	va_start(list, form);
	while (form[i])
	{
		if (i != 0 && form[i - 1] == '%' && form[i] != '%')
		{
			tmp = find_index(form[i]);
			if (tmp != -1)
				(*f[tmp])(&list, form);
			else
				write(1, &form[i], 1);
		}
		else if (form[i] != '%' || (form[i - 1] == '%' && form[i] == '%'))
			write(1, &form[i], 1);
		i++;
	}
	return (1);
}
