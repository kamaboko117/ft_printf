/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dotpad1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:42:49 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/29 16:07:08 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int	dotpad(va_list *list, const char *form)
{
	int i;
	int	tmp;
	int	len;

	len = form[1] == '*' ? va_arg(*list, int) : ft_atoi(form + 1);
	i = form[1] == '*' ? 2 : 1;
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	tmp = find_index(form[i]);
	if (tmp == 1)
		return (dotpadstr(list, len) - i);
	if (tmp == 2)
		return (dotpadptr(list, len) - i);
	else if (tmp >= 3 && tmp <= 4)
		return (dotpadnbr(list, len) - i);
	if (tmp == 5)
		return (dotpadnbru(list, len) - i);
	else if (tmp == 6)
		return (dotpadhex(list, len) - i);
	else if (tmp == 7)
		return (dotpadhexc(list, len) - i);
	return (0);
}

int	dotpadstr(va_list *list, int len)
{
	char *str;

	str = va_arg(*list, char*);
	if (str == NULL && len < 0)
		return (ft_putmaxstr("(null)", 6));
	len = len < 0 ? ft_strlen(str) : len;
	if (str == NULL)
		return (ft_putmaxstr("(null)", len));
	return (ft_putmaxstr(str, len));
}

int	dotpadhexc(va_list *list, int len)
{
	unsigned int	nb;
	int				ret;

	nb = va_arg(*list, unsigned int);
	ret = len > ft_numlen(nb, 16) ? len : ft_numlen(nb, 16);
	while (len > ft_numlen(nb, 16))
	{
		write(1, "0", 1);
		len--;
	}
	if (len == 0 && nb == 0)
		return (0);
	ft_putnbrbase_fd(nb, "0123456789ABCDEF", 1);
	return (ret);
}

int	dotpadhex(va_list *list, int len)
{
	unsigned int	nb;
	int				ret;

	nb = va_arg(*list, unsigned int);
	ret = len > ft_numlen(nb, 16) ? len : ft_numlen(nb, 16);
	while (len > ft_numlen(nb, 16))
	{
		write(1, "0", 1);
		len--;
	}
	if (len == 0 && nb == 0)
		return (0);
	ft_putnbrbase_fd(nb, "0123456789abcdef", 1);
	return (ret);
}

int	dotpadptr(va_list *list, int len)
{
	intptr_t	nb;
	int			ret;

	nb = va_arg(*list, intptr_t);
	ret = len > ft_numlen(nb, 16) + 2 ? len : ft_numlen(nb, 16);
	while (len > ft_numlen(nb, 16))
	{
		write(1, "0", 1);
		len--;
	}
	write(1, "0x", 2);
	if (len == 0 && nb == 0)
		return (2);
	ft_putnbrbase_fd(nb, "0123456789abcdef", 1);
	return (ret);
}
