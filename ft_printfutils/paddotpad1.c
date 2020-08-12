/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paddotpad1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:52:40 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/12 15:45:56 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	paddotpad(va_list *list, const char *form, int len)
{
	int tmp;
	int i;

	i = strnumlen(form + 1);
	tmp = find_index(form[i + 1]);
	if (len < 0)
		return (starleftpdp(list, form, -len));
	if (tmp == 1)
		return (paddotpadstr(list, form + i, len));
	if (tmp == 2)
		return (paddotpadptr(va_arg(*list, intptr_t), form + i, len) + 1);
	if (tmp >= 3 && tmp <= 5)
		return (paddotpaddec(va_arg(*list, int), form, len) - i + 1);
	if (tmp == 6)
		return (pdphex(va_arg(*list, unsigned int), form + i, len, 1) + 1);
	if (tmp == 7)
		return (pdphex(va_arg(*list, unsigned int), form + i, len, 0) + 1);
	if (tmp == 11)
		return (pdpstar(list, form + 1, len));
	if (tmp == 21)
		return (padpercent(form + i, len) + 1);
	return (0);
}

int	starleftpdp(va_list *list, const char *form, int len)
{
	int	i;
	int ret;
	int tmp;
	int dotlen;

	dotlen = form[1] == '*' ? va_arg(*list, int) : ft_atoi(form + 1);
	i = form[1] == '*' ? 2 : strnumlen(form + 1);
	ret = len + 1;
	tmp = find_index(form[i]);
	if (tmp == 1)
		len -= (dotpadstr(list, dotlen));
	if (tmp == 2)
		len -= (dotpadptr(list, dotlen));
	else if (tmp >= 3 && tmp <= 4)
		len -= (dotpadnbr(list, dotlen));
	if (tmp == 5)
		len -= (dotpadnbru(list, dotlen));
	else if (tmp == 6)
		len -= (dotpadhex(list, dotlen));
	else if (tmp == 7)
		len -= (dotpadhexc(list, dotlen));
	return (leftpadend(ret, i, len, form));
}

int	pdpstar(va_list *list, const char *form, int len)
{
	int	dl;
	int tmp;

	dl = va_arg(*list, int);
	tmp = find_index(form[1]);
	if (tmp == 1)
		return (pdpsstr(list, len, dl) - 1);
	if (tmp >= 3 && tmp <= 5)
		return (pdpsdec(va_arg(*list, int), len, dl));
	if (tmp == 6)
		return (pdpshex(va_arg(*list, unsigned int), len, dl));
	if (tmp == 7)
		return (pdpshexc(va_arg(*list, unsigned int), len, dl));
	return (0);
}

int	pdpsstr(va_list *list, int len, int size)
{
	char	*str;
	int		i;
	int		ret;

	ret = len;
	i = 0;
	if (!(str = va_arg(*list, char*)))
		str = "(null)";
	if (ft_strlen(str) < (unsigned long)size)
		size = ft_strlen(str);
	while (len > size)
	{
		write(1, " ", 1);
		len--;
	}
	while (str[i] && i < size)
	{
		write(1, &str[i], 1);
		i++;
	}
	if (size < ret)
		return (ret);
	return (size);
}

int	pdpsdec(int nb, int len, int zl)
{
	int i;
	int j;
	int sign;
	int	oldzl;

	sign = nb < 0 ? 1 : 0;
	oldzl = zl;
	zl = zl < ft_numlen(nb, 10) ? ft_numlen(nb, 10) : zl;
	if (sign == 1)
		nb = -nb;
	i = 0;
	while (i++ + sign < len - zl)
		write(1, " ", 1);
	if (sign == 1)
		write(1, "-", 1);
	j = 0;
	while (j++ < zl - ft_numlen(nb, 10))
		write(1, "0", 1);
	if (oldzl != 0 || nb != 0)
		ft_putnbr_fd(nb, 1);
	else
		write(1, " ", 1);
	return (i + zl + sign - 2);
}
