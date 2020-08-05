/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:45:42 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/05 17:46:43 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	paddec(va_list *list, int len, int j)
{
	int	nb;
	int	ret;
	int	i;

	nb = va_arg(*list, int);
	ret = len;
	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		len--;
		i = 1;
	}
	while (len-- > ft_numlen(nb, 10))
		write(1, " ", 1);
	if (i == 1)
		write(1, "-", 1);
	ft_putnbr_fd(nb, 1);
	if (ret >= ft_numlen(nb, 10) + i)
		return (ret - j);
	else
		return ((ft_numlen(nb, 10) + i) - j);
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
