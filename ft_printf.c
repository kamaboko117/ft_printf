/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:54:47 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/05 20:34:21 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h>

int	checkpercent(const char *form, int tmp)
{
	char	*str;
	int		i;

	str = "cspdiuxX-0.*123456789";
	if (tmp == 21)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == form[1])
				return (1);
			i++;
		}
	}
	return (0);
}

int	checkcondition(const char *form, int tmp)
{
	int	i;

	i = 0;
	if (form[i + 1] == '\0')
		return (i);
	if (checkpercent(form, tmp))
		return (1);
	while ((tmp >= 8 && tmp <= 20) && ((form[i] >= '0' && form[i] <= '9')
		|| form[i] == '-' || form[i] == '.' || form[i] == '*'))
	{
		if (form[i + 1] == '\0')
			return (i);
		i++;
	}
	return (i);
}

int	ft_printf(const char *form, ...)
{
	int		(**f)(va_list *, const char *);
	va_list	list;
	int		i;
	int		tmp;
	int		len;

	f = tabinit();
	i = -1;
	len = 0;
	va_start(list, form);
	while (form && form[++i])
	{
		tmp = 0;
		if (i != 0 && form[i - 1] == '%')
		{
			if ((tmp = find_index(form[i])) != -1)
				len += (*f[tmp])(&list, form + i) - 2;
		}
		else if (form[i] != '%')
			write(1, &form[i], 1);
		i += i == -1 ? 0 : checkcondition(form + i, tmp);
	}
	return (len + i);
}
