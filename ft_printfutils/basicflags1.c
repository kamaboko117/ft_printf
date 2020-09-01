/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicflags1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:36:18 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/12 16:44:50 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
		return (6);
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
	return (ft_numlen(nbr, 10));
}
