/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:54:47 by asaboure          #+#    #+#             */
/*   Updated: 2020/02/04 17:45:14 by asaboure         ###   ########.fr       */
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

void	hex(va_list *list)
{
	while (list);
}

void	nbr(va_list *list)
{
	int	nbr;

	nbr = va_arg(*list, int);
	ft_putnbr_fd(nbr, 1);
}

void	nbrhex(va_list *list)
{
	while (list);
}

int		ft_printf(const char *format, ...)
{
	void	(*functions[8])(va_list *) = {chr, str, hex, nbr, nbr, nbr, nbrhex, nbrhex};
	char	flags[9] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', 0};
	va_list	list;
	int		i;
	int		tmp;

	tmp = 0;
	i = 0;
	va_start(list, format);
	while (format[i++])
	{
		if (i != 0 && format[i - 1] == '%' && format[i] != '%')
		{
			tmp = find_index(flags, format[i]);
		//	printf("index: %d\n", tmp);
			if (tmp != -1)
				(*functions[tmp])(&list);
		}
		else if (format[i] != '%')
			write(1, &format[i], 1);
	}
	return (1);
}
