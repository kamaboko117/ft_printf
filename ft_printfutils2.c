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
	unsigned int	nbr;

	(void)form;
	nbr = va_arg(*list, unsigned int);
	ft_putnbrbase_fd(nbr, "0123456789ABCDEF", 1);
	return (ft_numlen(nbr, 16));
}

int	nbrhex(va_list *list, const char *form)
{
	unsigned int	nbr;

	(void)form;
	nbr = va_arg(*list, unsigned int);
	ft_putnbrbase_fd(nbr, "0123456789abcdef", 1);
	return (ft_numlen(nbr, 16));
}

int	zeropad(va_list *list, const char *form)
{
	int i;
	int tmp;
	int	mode;

	i = 1;
	if (form[1] == '.')
		dotpad(list, form + 1);
	if (form[1] == '-')
		return (leftpad(list, form + 1) - 1);
	while (form[i] >= '0' && form[i] <= '9')
		if (form[1 + i++] == '.')
			return (pad(list, form + 1) - 1);
	i = form[1] == '*' ? 2 : 1;
	mode = form[1] == '*' ? 1 : 0;
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

	len = form[1] == '*' ? va_arg(*list, int) : ft_atoi(form + 1);
	i = form[1] == '*' ? 2 : 1;
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	tmp = find_index(form[i]);
	if (tmp == 1)
		return (dotpadstr(list, len) - i);
	if (tmp == 2)
		return (dotpadptr(list, len) - i);
	else if (tmp >= 3 && tmp <= 5)
		return (dotpadnbr(list, len) - i);
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
	len = len < 0 ? ft_strlen(str) : len;
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
	len = form[1] == '*' ? va_arg(*list, int) : ft_atoi(form + 1);
	len = len < 0 ? -len : len;
	i = form[1] == '*' ? 2 : 1;
	ret = len;
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	if ((tmp = find_index(form[i])) == - 1)
		return (0);
	len -= (*f[tmp])(list, form + i);
	return (leftpadend(ret, i, len, form));
}
