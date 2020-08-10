/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paddotpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:52:40 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/10 19:15:24 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int	paddotpad(va_list *list, const char *form, int len)
{
	int tmp;
	int i;

	i = strnumlen(form + 1);
	tmp = find_index(form[i + 1]);
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
		return(pdpstar(list, form + 1, len));
	if (tmp == 21)
		return (padpercent(form + i, len) + 1);
	return (0);
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

int	pdpsdec(unsigned int nb, int len, int zl)
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
	if (oldzl != 0)
		ft_putnbr_fd(nb, 1);
	else
		write(1, " ", 1);
	return (i + zl + sign - 2);
}

int	pdpshexc(unsigned int nb, int len, int zl)
{
	int		oldzl;
	int		i;
	int		j;

	oldzl = zl;
	zl = zl < ft_numlen(nb, 16) ? ft_numlen(nb, 16) : zl;
	i = 0;
	while (i++ < len - zl)
		write(1, " ", 1);
	j = 0;
	while (j++ < zl - ft_numlen(nb, 16))
		write(1, "0", 1);
	if (oldzl != 0)
		ft_putnbrbase_fd(nb, "0123456789ABCDEF", 1);
	else
		write(1, " ", 1);
	return (i + zl - 2);
}

int	pdpshex(unsigned int nb, int len, int zl)
{
	int		oldzl;
	int		i;
	int		j;

	oldzl = zl;
	zl = zl < ft_numlen(nb, 16) ? ft_numlen(nb, 16) : zl;
	i = 0;
	while (i++ < len - zl)
		write(1, " ", 1);
	j = 0;
	while (j++ < zl - ft_numlen(nb, 16))
		write(1, "0", 1);
	if (oldzl != 0)
		ft_putnbrbase_fd(nb, "0123456789abcdef", 1);
	else
		write(1, " ", 1);
	return (i + zl - 2);
}

int	paddotpadstr(va_list *list, const char *form, int len)
{
	int		size;
	char	*str;
	int		i;
	int		ret;

	ret = len;
	i = 0;
	if (!(str = va_arg(*list, char*)))
		str = "(null)";
	size = ft_atoi(form);
	if (ft_strlen(str) < (unsigned long)ft_atoi(form))
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
		return (ret - strnumlen(form));
	return (size - strnumlen(form));
}

int	paddotpadptr(unsigned int n, const char *f, int len)
{
	int	zl;
	int	i;
	int j;

	zl = ft_atoi(f) < ft_numlen(n, 16) + 2 ? ft_numlen(n, 16) + 2 : ft_atoi(f);
	i = 0;
	while (i++ <= len - zl)
		write(1, " ", 1);
	j = 0;
	write(1, "0x", 2);
	while (j++ < zl - ft_numlen(n, 16) - 2)
		write(1, "0", 1);
	if (ft_atoi(f) != 0)
		ft_putnbrbase_fd(n, "0123456789abcdef", 1);
	return (i + zl - strnumlen(f) - 3);
}

int	pdphex(unsigned int nb, const char *f, int len, int mode)
{
	int		zl;
	int		i;
	int		j;
	char	*base;

	base = mode == 1 ? "0123456789abcdef" : "0123456789ABCDEF";
	zl = ft_atoi(f) < ft_numlen(nb, 16) ? ft_numlen(nb, 16) : ft_atoi(f);
	i = 0;
	while (i++ < len - zl)
		write(1, " ", 1);
	j = 0;
	while (j++ < zl - ft_numlen(nb, 16))
		write(1, "0", 1);
	if (ft_atoi(f) != 0)
		ft_putnbrbase_fd(nb, base, 1);
	else
		write(1, " ", 1);
	return (i + zl - strnumlen(f) - 2);
}

int	paddotpaddec(int nb, const char *form, int len)
{
	int zerolen;
	int i;
	int j;
	int sign;

	sign = nb < 0 ? 1 : 0;
	zerolen = ft_atoi(form + 1);
	zerolen = zerolen < ft_numlen(nb, 10) ? ft_numlen(nb, 10) : zerolen;
	if (sign == 1)
		nb = -nb;
	i = 0;
	while (i++ + sign < len - zerolen)
		write(1, " ", 1);
	if (sign == 1)
		write(1, "-", 1);
	j = 0;
	while (j++ < zerolen - ft_numlen(nb, 10))
		write(1, "0", 1);
	if (ft_atoi(form + 1) != 0 || nb != 0)
		ft_putnbr_fd(nb, 1);
	else
		write(1, " ", 1);
	return (i + zerolen + sign - strnumlen(form) - 2);
}
