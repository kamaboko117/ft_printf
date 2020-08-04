/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:39:24 by asaboure          #+#    #+#             */
/*   Updated: 2020/07/03 13:53:19 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	chr(va_list *list, const char *form)
{
	int chr;

	(void)form;
	chr = va_arg(*list, int);
	ft_putchar_fd(chr, 1);
	return (1);
}

int	str(va_list *list, const char *form)
{
	char	*str;

	(void)form;
	str = va_arg(*list, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return(6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ptr(va_list *list, const char *form)
{
	intptr_t	ptr;

	(void)form;
	ptr = va_arg(*list, intptr_t);
	write(1, "0x", 2);
	ft_putnbrbase_fd(ptr, "0123456789abcdef", 1);
	return (ft_numlen(ptr, 16) + 2);
}

int	nbr(va_list *list, const char *form)
{
	int	nbr;

	(void)form;
	nbr = va_arg(*list, int);
	ft_putnbr_fd(nbr, 1);
	if (nbr < 0)
		return (ft_numlen(nbr, 10) + 1);
	return (ft_numlen(nbr, 10));
}

int	nbru(va_list *list, const char *form)
{
	unsigned int	nbr;

	(void)form;
	nbr = va_arg(*list, unsigned int);
	ft_putnbru_fd(nbr, 1);
	if (nbr < 0)
		return (ft_numlen(nbr, 10) + 1);
	return (ft_numlen(nbr, 10));
}

int	(**tabinit(void))(va_list *, const char *)
{
	int (**f)(va_list *, const char *);

	if (!(f = malloc(22 * sizeof(*f))))
		return (NULL);
	f[0] = chr;
	f[1] = str;
	f[2] = ptr;
	f[3] = nbr;
	f[4] = nbr;
	f[5] = nbru;
	f[6] = nbrhex;
	f[7] = nbrhexcaps;
	f[8] = leftpad;
	f[9] = zeropad;
	f[10] = dotpad;
	f[11] = pad;
	f[12] = pad;
	f[13] = pad;
	f[14] = pad;
	f[15] = pad;
	f[16] = pad;
	f[17] = pad;
	f[18] = pad;
	f[19] = pad;
	f[20] = pad;
	f[21] = percent;
	return (f);
}

int	percent(va_list *list, const char *form)
{
	(void)list;
	write(1, "%", 1);
	if (form[1])
	{
		write(1, &form[1], 1);
		return(1);
	}
	return(1);
}

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
	if (tmp == 0)
		return (padchr(list, len) - strnumlen(form));
	if (tmp == 1)
		return (padstr(list, len) - i);
	if (tmp == 2)
		return (padptr(list, len) - strnumlen(form) + 1);
	if (tmp >= 3 && tmp <= 5)
		return (paddec(list, len) + 1);
	if (tmp == 6)
		return (padhex(list, len));
	if (tmp == 7)
		return (padhexc(list, len));
	if (tmp == 21)
		return (padpercent(list, len));
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
	return(i);
}

int	padptr(va_list *list, int len)
{
	intptr_t	ptr;
	int diff;
	int	ret;

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
		return (paddotpaddec(va_arg(*list, int), form + i, len) + 1);
	if (tmp == 6)
		return (paddotpadhex(va_arg(*list, unsigned int), form + i, len, 1) + 1);
	if (tmp == 7)
		return (paddotpadhex(va_arg(*list, unsigned int), form + i, len, 0) + 1);
	if (tmp == 21)
		return (padpercent(list, len) + 1);
	return (0);
}

int	paddotpadstr(va_list *list, const char *form, int len)
{
	int		size;
	char	*str;
	int		i;
	int		ret;

	ret = len;
	i = 0;
	if(!(str = va_arg(*list, char*)))
		str = "(null)";
	size = ft_atoi(form);
	if (ft_strlen(str) < (unsigned long)ft_atoi(form))
		size = ft_strlen(str);
	while (len > size)
	{
		write(1, " ", 1);
		len--;
	}
	while(str[i] && i < size)
	{
		write(1, &str[i], 1);
		i++;
	}
	if (size < ret)
		return (ret - strnumlen(form));
	return (size - strnumlen(form));
}

int	padstr(va_list *list, int len)
{
	unsigned long i;
	unsigned long rlen;
	char *str;

	i = 0;
	rlen = len;
	str = va_arg(*list, char *);
	if (str == NULL)
	{
		while(i++ + 6 < rlen)
			write(1, " ", 1);
		write(1, "(null)", 6);
		if (rlen > 6)
			return(len);
		return(6);
	}
	if (rlen > ft_strlen(str))
	{
		while(i++ < rlen - ft_strlen(str))
			write(1, " ", 1);
		ft_putstr_fd(str, 1);
		return(len);
	}
	ft_putstr_fd(str, 1);
	return(ft_strlen(str));
}

int padpercent(va_list *list, int len)
{
	int i;

	i = 1;
	(void)list;
	while(i < len)
	{
		write(1, " ", 1);
		i++;
	}
	write(1, "%", 1);
	return(len - 1);
}

int	paddotpadptr(unsigned int nb, const char *form, int len)
{
	int	zerolen;
	int	i;
	int j;

	zerolen = ft_atoi(form) < ft_numlen(nb, 16) + 2 ? ft_numlen(nb, 16) + 2 : ft_atoi(form);
	i = 0;
	while (i++ <= len - zerolen)
		write(1, " ", 1);
	j = 0;
	write(1, "0x", 2);
	while (j++ < zerolen - ft_numlen(nb, 16) - 2)
		write(1, "0", 1);
	if (ft_atoi(form) != 0)
		ft_putnbrbase_fd(nb, "0123456789abcdef", 1);
	return (i + zerolen - strnumlen(form) - 3);
}

int	paddotpadhex(int nb, const char *form, int len, int mode)
{
	int	zerolen;
	int	i;
	int j;
	char	*base;

	base = mode == 1 ? "0123456789abcdef" : "0123456789ABCDEF";
	zerolen = ft_atoi(form) < ft_numlen(nb, 16) ? ft_numlen(nb, 16) : ft_atoi(form);
	i = 0;
	while (i++ < len - zerolen)
		write(1, " ", 1);
	j = 0;
	while (j++ < zerolen - ft_numlen(nb, 16))
		write(1, "0", 1);
	if (ft_atoi(form) != 0)
		ft_putnbrbase_fd(nb, base, 1);
	else
		write(1, " ", 1);
	return (i + zerolen - strnumlen(form) - 2);
}

int paddotpaddec(int nb, const char *form, int len)
{
	int zerolen;
	int i;
	int j;
	int sign;

	sign = nb < 0 ? 1 : 0;
	zerolen = ft_atoi(form);
	zerolen = zerolen < ft_numlen(nb, 10) ? ft_numlen(nb, 10) : zerolen;
	if (sign == 1)
		nb = -nb;
	i = 0;
	while (i++ + sign < len - zerolen)
		write(1, " ", 1);
	if (sign == 1)
		write(1, "-", 1);
	j = 0;
	while (j++  < zerolen - ft_numlen(nb,10))
		write(1, "0", 1);
	if (ft_atoi(form) != 0)
		ft_putnbr_fd(nb, 1);
	else
		write(1, " ", 1);
	return (i + zerolen + sign - strnumlen(form) - 2);
}

int	paddec(va_list *list, int len)
{
	int	nb;
	int	ret;
	int	i;

	nb = va_arg(*list, int);
	ret = len - ft_numlen(len, 10) - 1;
	i = 1;
	if (nb < 0)
	{
		nb = -nb;
		len--;
		i = 0;
	}
	while (len-- > ft_numlen(nb, 10))
		write(1, " ", 1);
	if (i == 0)
		write(1, "-", 1);
	ft_putnbr_fd(nb, 1);
	if (ret >= ft_numlen(nb, 10) - i)
		return (ret);
	else
		return (ft_numlen(nb, 10) - i - 1);
}

int	padhex(va_list *list, int len)
{
	int	nb;
	int	diff;
	int ret;

	nb = va_arg(*list, int);
	diff = len - ft_numlen(len, 16) - 1;
	ret = len;
	while (len-- > ft_numlen(nb, 16))
		write(1, " ", 1);
	ft_putnbrbase_fd(nb, "0123456789abcdef", 1);
	if (diff >= ft_numlen(nb, 16) - 1)
		return (ret - 1);
	else
		return (ft_numlen(nb, 16) - 1);
}

int	padhexc(va_list *list, int len)
{
	int	nb;
	int	diff;
	int ret;

	nb = va_arg(*list, int);
	diff = len - ft_numlen(len, 16) - 1;
	ret = len;
	while (len-- > ft_numlen(nb, 16))
		write(1, " ", 1);
	ft_putnbrbase_fd(nb, "0123456789ABCDEF", 1);
	if (diff >= ft_numlen(nb, 16) - 1)
		return (ret - 1);
	else
		return (ft_numlen(nb, 16) - 1);
}

