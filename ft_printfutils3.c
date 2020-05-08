/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 20:55:15 by asaboure          #+#    #+#             */
/*   Updated: 2020/05/08 21:15:22 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	dotpadhexc(va_list *list, int len)
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

int	dotpadhex(va_list *list, int len)
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

int	dotpadnbr(va_list *list, int len)
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

int	zeropaddecend(int nb, int ret, int i)
{
	ft_putnbr_fd(nb, 1);
	if (ret >= ft_numlen(nb, 10) - i - 1)
		return (ret);
	else
		return (ft_numlen(nb, 10) - i - 1);
}
