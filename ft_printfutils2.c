/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:42:49 by asaboure          #+#    #+#             */
/*   Updated: 2020/05/08 21:27:57 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int	nbr;

	(void)form;
	nbr = va_arg(*list, int);
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
	if (form[i] == '*')
	{
		mode = 1;
		i++;
	}
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	tmp = find_index(form[i]);
	if (tmp >= 3 && tmp <= 5)
		return (zeropaddec(mode, list, form, '0'));
	if (tmp == 6)
		return (zeropadhex(mode, list, form, '0'));
	if (tmp == 7)
		return (zeropadhexc(mode, list, form, '0'));
	return (0);
}

int	dotpad(va_list *list, const char *form)
{
	int i;
	int	tmp;
	int	len;

	i = 1;
	if (form[i] == '*')
	{
		len = va_arg(*list, int);
		i++;
	}
	else
		len = ft_atoi(form + i);
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	tmp = find_index(form[i]);
	if (tmp == 1)
		return (ft_putmaxstr(va_arg(*list, char *), len) - ft_numlen(len, 10)
				- 1);
	else if (tmp >= 3 && tmp <= 5)
		return (dotpadnbr(list, len) - ft_numlen(len, 10) - 1);
	else if (tmp == 6)
		return (dotpadhex(list, len) - ft_numlen(len, 10) - 1);
	else if (tmp == 7)
		return (dotpadhexc(list, len) - ft_numlen(len, 10) - 1);
	return (0);
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
	tmp = find_index(form[i]);
	len -= (*f[tmp])(list, form + i);
	return (leftpadend(ret, i, len, form));
}
