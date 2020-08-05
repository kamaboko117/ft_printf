/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dotpad2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 20:55:15 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/05 18:07:58 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	dotpadnbr(va_list *list, int len)
{
	int	nb;
	int ret;
	int	s;

	if (len == 0)
		return (0);
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