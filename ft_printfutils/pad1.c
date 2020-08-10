/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:42:55 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/10 18:13:47 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
		return (padchr(list, len) - strnumlen(form));
	if (tmp == 1)
		return (padstr(list, len) - i);
	if (tmp == 2)
		return (padptr(list, len) - strnumlen(form) + 1);
	if (tmp >= 3 && tmp <= 5)
		return (paddec(list, len, i));
	if (tmp == 6)
		return (padhex(list, len));
	if (tmp == 7)
		return (padhexc(list, len));
	return (padelse(form, len, tmp, i));
}

int	padelse(const char *form, int len, int tmp, int i)
{
	if (tmp == 21)
		return (padpercent(form + i, len) - i + 1);
	return (0);
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

int	padstr(va_list *list, int len)
{
	unsigned long	i;
	unsigned long	rlen;
	char			*str;

	i = 0;
	rlen = len;
	str = va_arg(*list, char *);
	if (str == NULL)
	{
		while (i++ + 6 < rlen)
			write(1, " ", 1);
		write(1, "(null)", 6);
		if (rlen > 6)
			return (len);
		return (6);
	}
	if (rlen > ft_strlen(str))
	{
		while (i++ < rlen - ft_strlen(str))
			write(1, " ", 1);
		ft_putstr_fd(str, 1);
		return (len);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
