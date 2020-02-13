/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:54:47 by asaboure          #+#    #+#             */
/*   Updated: 2020/02/13 15:36:03 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int		zeropad(va_list *list, const char *format)
{
	int	i;
	int	len;
	int	tmp;
	int	nbr;

	nbr = va_arg(*list, int);
	i = ft_atoi(format);
	tmp = ft_numlen(i, 10) + 1;
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
int		dotpad(va_list *list, const char *form)
{
	int	nbr;
	int	i;

	nbr = va_arg(*list, int);
	i = ft_atoi(form + 1);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	while (i-- > 0)
		write(1, "0", 1);
return 0;	
}

int		pad(va_list *list, const char *form)
{
	int	ret;
	
	ret = 0;
	if (form[0] == '.')
		ret = dotpad(list, form);
	if (form[0] == '0' && form[1] == '.')
		ret = dotpad(list, form + 1);
	else
		ret = zeropad(list, form);
	return (ret);
}

int		ft_printf(const char *form, ...)
{
	void	(*f[8])(va_list *) = {chr, str, ptr, nbr, nbr, nbr, nbrhex, nbrhex};
	va_list	list;
	int		i;
	int		tmp;

	tmp = 0;
	i = 1;
	va_start(list, form);
	while (form[i])
	{
		if (i != 0 && form[i - 1] == '%' && form[i] != '%')
		{
			if (form[i] == '0' || form[i] == '.')
				i += pad(&list, form + i);
			tmp = find_index(form[i]);
			if (tmp != -1)
				(*f[tmp])(&list);
			else
				write(1, &form[i], 1);
		}
		else if (form[i] != '%' || (form[i - 1] == '%' && form[i] == '%'))
			write(1, &form[i], 1);
		i++;
	}
	return (1);
}
