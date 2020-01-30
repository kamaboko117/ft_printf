/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:54:47 by asaboure          #+#    #+#             */
/*   Updated: 2020/01/30 18:35:51 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

int	find_index(char *tab, char c)
{
	int	i;

	i = 0;
	while (tab[i++])
	{
		if (tab[i] == c)
			return (i);
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	void	(*functions[3])(va_list *) = {str, nbr, chr}
	char	flags[4] = {'s', 'd', 'c', 0};
	va_list	list;
	int		i;
	int		tmp;

	tmp = 0;
	i = 0;
	va_start(list, format);
	while (format[i++])
	{
		if (i != 0 && format[i - 1] == '%')
		{
			tmp = find_index(flags, format[i]);
			if (tmp != -1)
				(*functions[tmp])(&list);
		}
		else if (format[i] != '%')
			write(1, &format[i], 1);
	}
}
