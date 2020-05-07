/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:42:49 by asaboure          #+#    #+#             */
/*   Updated: 2020/05/08 00:56:50 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

int	(**tabinit(void))(va_list *, const char *)
{
	int (**f)(va_list *, const char *);
	
	if (!(f = malloc(11 * sizeof *f)))
		return(NULL);
	f[0] = chr;
	f[1] = str;
	f[2] = ptr;
	f[3] = nbr;
	f[4] = nbr;
	f[5] = nbr;
	f[6] = nbrhex;
	f[7] = nbrhexcaps;
	f[8] = leftpad;
	f[9] = zeropad;
	f[10] = dotpad;
	return (f);
}

int	find_index(char c)
{
	int		i;
	char	*tab;

	tab = "cspdiuxX-0.*";
	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	nbrhexcaps(va_list *list, const char *form)
{
	int	nbr;

	(void)form;
	nbr = va_arg(*list, int);
	ft_putnbrbase_fd(nbr, "0123456789ABCDEF", 1);
	return(ft_numlen(nbr, 16));
}

int	nbrhex(va_list *list, const char *form)
{
	int	nbr;

	(void)form;
	nbr = va_arg(*list, int);
	ft_putnbrbase_fd(nbr, "0123456789abcdef", 1);
	return(ft_numlen(nbr, 16));
}

int	zeropad(va_list *list, const char *form)
{
	int i;
	int tmp;

	if (form[1] == '.')
		dotpad(list, form + 1);
	i = 0;
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	tmp = find_index(form[i]);
	if (tmp >= 3 && tmp <= 5)
		return (zeropaddec(list, form));
	if (tmp == 6)
		return (zeropadhex(list, form));
	if (tmp == 7)
		return (zeropadhexc(list, form));
	return (0);
}

int	zeropaddec(va_list *list, const char *form)
{
	int	nb;
	int	len;
	int	ret;
	int	i;

	nb = va_arg(*list, int);
	len = ft_atoi(form + 1);
	ret = len - ft_numlen(len, 10) - 1;
	i = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		len--;
		i = 0;
	}
	while (len-- > ft_numlen(nb, 10))
		write(1, "0", 1);
	ft_putnbr_fd(nb, 1);
	if (ret >= ft_numlen(nb, 10) - i -1)
		return (ret);
	else
		return (ft_numlen(nb, 10) - i -1);
}

int	zeropadhex(va_list *list, const char *form)
{
	int	nb;
	int	len;
	int	ret;
	int	i;

	nb = va_arg(*list, int);
	len = ft_atoi(form + 1);
	ret = len - ft_numlen(len, 16) - 1;
	i = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		len--;
		i = 0;
	}
	while (len-- > ft_numlen(nb, 16))
		write(1, "0", 1);
	ft_putnbrbase_fd(nb, "0123456789abcdef", 1);
	if (ret >= ft_numlen(nb, 16) - i -1)
		return (ret);
	else
		return (ft_numlen(nb, 16) - i -1);
}

int	zeropadhexc(va_list *list, const char *form)
{
	int	nb;
	int	len;
	int	ret;
	int	i;

	nb = va_arg(*list, int);
	len = ft_atoi(form + 1);
	ret = len - ft_numlen(len, 16) - 1;
	i = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		len--;
		i = 0;
	}
	while (len-- > ft_numlen(nb, 16))
		write(1, "0", 1);
	ft_putnbrbase_fd(nb, "0123456789ABCDEF", 1);
	if (ret >= ft_numlen(nb, 16) - i -1)
		return (ret);
	else
		return (ft_numlen(nb, 16) - i -1);
}

int	dotpad(va_list *list, const char *form)
{
	int i;
	int	tmp;
	int	len;

	i = 1;
	len = ft_atoi(form + i);
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	tmp = find_index(form[i]);
	if (tmp == 1)
		return (ft_putmaxstr(va_arg(*list, char *), len) - ft_numlen(len, 10) -1);
	else if (tmp >= 3 && tmp <= 5)
		return (dotpadnbr(list, len) - ft_numlen(len, 10) -1);
	else if (tmp == 6)
		return (dotpadhex(list, len) - ft_numlen(len, 10) -1);
	else if (tmp == 7)
		return (dotpadhexc(list, len) - ft_numlen(len, 10) -1);
	return (0);
}

int dotpadhexc(va_list *list, int len)
{
	int	nb;
	int	ret;

	ret = len;
	nb = va_arg(*list, int);
	while (len > ft_numlen(nb, 16))
	{
		write(1, "0", 1);
		len--;
	}
	ft_putnbrbase_fd(nb, "0123456789ABCDEF", 1);
	return (ret);
}

int dotpadhex(va_list *list, int len)
{
	int	nb;
	int	ret;

	ret = len;
	nb = va_arg(*list, int);
	while (len > ft_numlen(nb, 16))
	{
		write(1, "0", 1);
		len--;
	}
	ft_putnbrbase_fd(nb, "0123456789abcdef", 1);
	return (ret);
}
	
int dotpadnbr(va_list *list, int len)
{
	int	nb;
	int ret;
	int	s;

	s = 0;
	ret = len;
	if ((nb = va_arg(*list, int)) < 0)
		{
			write(1, "-", 1);
			nb = -nb;
			s = 1;
		}
		while (len > ft_numlen(nb, 10))
		{
			write(1, "0", 1);
			len--;
		}
		ft_putnbr_fd(nb, 1);
	if (ret + s <= ft_numlen(nb, 10) + s)
		return (ft_numlen(nb, 10) + s);
	return (ret + s);
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
	if (form[i++] ==  '*')
		len = va_arg(*list, int);
	ret = len - 3;
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	tmp = find_index(form[i]);
	len -= (*f[tmp])(list, form + i);
	while(len-- > 0)
		write(1, " ", 1);
	if (len < 0)
		return (ret - len);
	return (ret);
}

int	ft_putmaxstr(const char *s, int len)
{
	int	i;
	int	tmp;

	tmp = ft_strlen(s);
	i = 0;
	while (s[i] && i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
	if (tmp <= len)
		return (tmp);
	return (len);
}