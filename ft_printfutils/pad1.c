/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:42:55 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/29 16:40:04 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int	pad(va_list *list, const char *form)
{
	int i;
	int tmp;
	int len;

	len = form[0] == '*' ? va_arg(*list, int) : ft_atoi(form);
	i = form[0] == '*' ? 1 : ft_numlen(len, 10);
	if (form[i] == '.')
		return (paddotpad(list, form + i, len) - (i + 1));
	tmp = find_index(form[i]);
	if (len < 0)
		return (starleftpad(list, form + i, -len, tmp));
	if (tmp == 0)
		return (padchr(list, len) - i);
	if (tmp == 1)
		return (padstr(list, len) - i);
	if (tmp == 2)
		return (padptr(list, len) - i + 1);
	if (tmp >= 3 && tmp <= 4)
		return (paddec(list, len, i));
	if (tmp == 5)
		return (padnbru(list, len) - i);
	if (tmp == 6)
		return (padhex(list, len) - i + 1);
	return (padelse(list, form, len, i));
}

int	padelse(va_list *list, const char *form, int len, int i)
{
	int tmp;

	tmp = find_index(form[i]);
	if (tmp == 7)
		return (padhexc(list, len) - i + 1);
	if (tmp == 21)
		return (padpercent(form + i, len) - i + 1);
	return (0);
}

int	padnbru(va_list *list, int len)
{
	unsigned int	nb;
	int				ret;

	nb = va_arg(*list, unsigned int);
	ret = len;
	while (len-- > ft_numlen(nb, 10))
		write(1, " ", 1);
	ft_putnbru_fd(nb, 1);
	if (ret >= ft_numlen(nb, 10))
		return (ret);
	else
		return (ft_numlen(nb, 10));
}

int	padchr(va_list *list, int len)
{
	int	c;
	int	i;

	c = va_arg(*list, int);
	i = 0;
	while (i++ < len - 1)
		write(1, " ", 1);
	write(1, &c, 1);
	return (i);
}

int	padptr(va_list *list, int len)
{
	intptr_t	ptr;
	int			diff;
	int			ret;

	ptr = va_arg(*list, intptr_t);
	diff = len - (ft_numlen(ptr, 16) + 2);
	ret = len;
	while (len-- - 2 > ft_numlen(ptr, 16))
		write(1, " ", 1);
	write(1, "0x", 2);
	ft_putnbrbase_fd(ptr, "0123456789abcdef", 1);
	if (diff >= 0)
		return (ret - 1);
	else
		return ((ft_numlen(ptr, 16) + 2) - 1);
}
