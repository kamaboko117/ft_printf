/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:42:49 by asaboure          #+#    #+#             */
/*   Updated: 2020/07/03 13:44:36 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	nbrhexcaps(va_list *list, const char *form)
{
	int	nbr;

	(void)form;
	nbr = va_arg(*list, int);
	ft_putnbrbase_fd(nbr, "0123456789ABCDEF", 1);
	return (ft_numlen(nbr, 16));
}

int	nbrhex(va_list *list, const char *form)
{
	unsigned int	nbr;

	(void)form;
	nbr = va_arg(*list, unsigned int);
	if (nbr == 4294967295)
	{
		write(1, "ffffffff", 8);
		return (8);
	}
	ft_putnbrbase_fd(nbr, "0123456789abcdef", 1);
	return (ft_numlen(nbr, 16));
}

int	zeropad(va_list *list, const char *form)
{
	int i;
	int tmp;
	int	mode;

	mode = 0;
	i = 1;
	if (form[i] == '.')
		dotpad(list, form + 1);
	if (form[i] == '-')
		return (leftpad(list, form));
	while (form[i] >= '0' && form[i] <= '9')
		if (form[1 + i++] == '.')
			return (pad(list, form + 1) - 1);
	i = 1;
	if (form[i] == '*')
	{
		mode = 1;
		i++;
	}
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	tmp = find_index(form[i]);
	if (tmp == 21)
		return zeropadpercent(mode, list, form);
	if (tmp >= 3 && tmp <= 5)
		return (zeropaddec(mode, list, form));
	if (tmp == 6)
		return (zeropadhex(mode, list, form));
	if (tmp == 7)
		return (zeropadhexc(mode, list, form));
	return (0);
}

int zeropadpercent(int mode, va_list *list, const char *form)
{
	int i;
	int len;

	(void)mode;
	(void)list;
	(void)form;
	len = ft_atoi(form + 1);
	i = 1;
	while (i < len)
	{
		write(1, "0", 1);
		i++;
	}
	write(1, "%", 1);
	return (len - 2);
}

int	dotpad(va_list *list, const char *form)
{
	int i;
	int	tmp;
	int	len;
	int size;

	i = 1;
	if (form[i] == '*')
	{
		len = va_arg(*list, int);
		i++;
	}
	else
		len = ft_atoi(form + i);
	size = strnumlen(form + i);
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	tmp = find_index(form[i]);
	if (tmp == 1)
		return (dotpadstr(list, len) - size - 1);
	else if (tmp >= 3 && tmp <= 5)
		return (dotpadnbr(list, len) - ft_numlen(len, 10) - size);
	else if (tmp == 6)
		return (dotpadhex(list, len) - ft_numlen(len, 10) - 1);
	else if (tmp == 7)
		return (dotpadhexc(list, len) - ft_numlen(len, 10) - 1);
	return (0);
}
int	dotpadstr(va_list *list, int len)
{
	char *str;

	str = va_arg(*list, char*);
	if (str == NULL)
		return(ft_putmaxstr("(null)", len));
	return(ft_putmaxstr(str, len));
}

int	strnumlen(const char *form)
{
	int i;

	i = 0;
	while(form[i] >= '0' && form[i] <= '9')
		i++;
	return (i);
}

int	leftpad(va_list *list, const char *form)
{
	int	tmp;
	int	i;
	int	(**f)(va_list *, const char *);
	int	len;
	int ret;

	f = tabinit();
	i = 1;
	len = ft_atoi(form + i);
	if (form[i] == '*')
	{
		len = va_arg(*list, int);
		i++;
	}
	ret = len;
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	if ((tmp = find_index(form[i])) == - 1)
		return (0);
	len -= (*f[tmp])(list, form + i);
	return (leftpadend(ret, i, len, form));
}
