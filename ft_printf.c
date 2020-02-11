/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:54:47 by asaboure          #+#    #+#             */
/*   Updated: 2020/02/11 19:45:27 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

int		find_index(char *tab, char c)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	chr(va_list *list)
{
	int chr;
	
	chr = va_arg(*list, int);
	ft_putchar_fd(chr, 1);
}

void	str(va_list *list)
{
	char	*str;

	str = va_arg(*list, char *);
	ft_putstr_fd(str, 1);
}

void	ptr(va_list *list)
{
	void	*ptr;

	ptr = va_arg(*list, void *);
	ft_putnbrbase_fd((intptr_t)ptr, "0123456789abcdef", 1);
}

void	nbr(va_list *list)
{
	int	nbr;

	nbr = va_arg(*list, int);
	ft_putnbr_fd(nbr, 1);
}

void	nbrhex(va_list *list)
{
	int	nbr;

	nbr = va_arg(*list, int);
	ft_putnbrbase_fd(nbr, "0123456789abcdef", 1);
}

int		zeropad(va_list *list, const char *format)
{
	int		i;
	int 	len;
	int 	tmp;
	int 	nbr;

	nbr = va_arg(*list, int);
	i = ft_atoi(format);
	tmp = ft_numlen(i, 10) + 1;
	printf("i: %d, nbr: %d\n", i, nbr);
	if (nbr < 0)
	{
		write(1, "-", 1);
		i--;
		nbr = -nbr;
	}
	if (format[tmp] == 'd' || format[tmp] == 'i' || format[tmp] == 'u')
		{
			len = ft_numlen(nbr, 10);
			while (len < i--)
				write(1, "0", 1);
			ft_putnbr_fd(nbr, 1);
	}
	if (format[tmp] == 'x' || format[tmp] == 'X')
		{
			len = ft_numlen(nbr, 16);
			while (len < i--)
				write(1, "0", 1);
			if (format[tmp] == 'x')
				ft_putnbrbase_fd(nbr, "0123456789abcdef", 1);
			if (format[tmp] == 'X')
				ft_putnbrbase_fd(nbr, "0123456789ABCDEF", 1);
		}
	return (tmp + 1);
}

int		ft_printf(const char *format, ...)
{
	void	(*functions[8])(va_list *) = {chr, str, ptr, nbr, nbr, nbr, nbrhex, nbrhex};
	char	flags[9] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', 0};
	va_list	list;
	int		i;
	int		tmp;

	tmp = 0;
	i = 1;
	va_start(list, format);
	while (format[i])
	{
		if (i != 0 && format[i - 1] == '%' && format[i] != '%')
		{
			if (format[i] == '0' || format[i] == '.')
				i += zeropad(&list, format + i);
			tmp = find_index(flags, format[i]);
		//	printf("index: %d\n", tmp);
			if (tmp != -1)
				(*functions[tmp])(&list);
			else
				write(1, &format[i], 1);
		}
		else if (format[i] != '%' || (format[i - 1] == '%' && format[i] ==  '%'))
			write(1, &format[i], 1);
		i++;
	}
	return (1);
}
