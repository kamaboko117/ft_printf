/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeropad2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:59:56 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/29 18:04:01 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	zeropaddec(int mode, va_list *list, const char *form)
{
	int	nb;
	int	len;
	int	ret;
	int	i;

	if (mode >= 1)
		len = va_arg(*list, int);
	else
		len = ft_atoi(form + 1);
	if (mode == 2)
		va_arg(*list, int);
	if (len < 0)
		return (starleftpad(list, form, -len, 3) - 1);
	nb = va_arg(*list, int);
	ret = len;
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
	return (zeropaddecend(nb, ret, i));
}

int	zeropaddecend(int nb, int ret, int i)
{
	ft_putnbr_fd(nb, 1);
	if (ret >= ft_numlen(nb, 10) - i + 1)
		return (ret);
	else
		return (ft_numlen(nb, 10) - i + 1);
}

int	zeropadpercent(int mode, va_list *list, const char *form)
{
	int i;
	int len;

	(void)mode;
	(void)list;
	len = ft_atoi(form + 1);
	i = 1;
	while (i < len)
	{
		write(1, "0", 1);
		i++;
	}
	write(1, "%", 1);
	i = 0;
	while (form[i])
	{
		if (form[i] == '%')
			break ;
		i++;
	}
	if (form[i + 1])
		write(1, &form[i + 1], 1);
	return (len - (strnumlen(form)));
}
