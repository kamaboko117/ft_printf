/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicflags2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:40:22 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/05 18:07:22 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	nbrhex(va_list *list, const char *form)
{
	unsigned int	nbr;

	(void)form;
	nbr = va_arg(*list, unsigned int);
	ft_putnbrbase_fd(nbr, "0123456789abcdef", 1);
	return (ft_numlen(nbr, 16));
}

int	nbrhexcaps(va_list *list, const char *form)
{
	unsigned int	nbr;

	(void)form;
	nbr = va_arg(*list, unsigned int);
	ft_putnbrbase_fd(nbr, "0123456789ABCDEF", 1);
	return (ft_numlen(nbr, 16));
}

int	percent(va_list *list, const char *form)
{
	(void)list;
	write(1, "%", 1);
	if (form[1])
	{
		write(1, &form[1], 1);
		return (1);
	}
	return (1);
}
