/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeropad1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 21:03:44 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/29 18:45:24 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int	checkzeropad(va_list *list, const char *form, int j, int mode)
{
	int 	size;
	int		i;
	int		tmp;
	va_list copy;

	i = 1;
	va_copy(copy, *list);
	if (form[1] == '*')
		va_arg(copy, int);
	size = form[j + 1] == '*' ? va_arg(copy, int) : ft_atoi(form);
	va_end(copy);
	if (size >= 0)
		return (pad(list, form + 1) - 1);
	mode = -1;
	if (form[1] == '*')
		mode = 2;
	while (form[i + j + 1] >= '0' && form[i + j + 1] <= '9')
		i++;
	tmp = find_index(form[i + j + 1]);
	return (zeropadend(list, form, tmp, mode) - (i + 1 + j));	
}

int	zeropad(va_list *list, const char *form)
{
	int i;
	int tmp;
	int	mode;

	i = 1;
	if (form[1] == '.')
		return (dotpad(list, form + 1) - 1);
	if (form[1] == '-')
		return (leftpad(list, form + 1) - 1);
	mode = form[1] == '*' ? 1 : 0;
	if (mode == 1 && checkneg(list))
		return (leftpad(list, form));
	while ((form[i] >= '0' && form[i] <= '9') || form[i] == '*')
		if (form[1 + i++] == '.')
			return (checkzeropad(list, form, i, mode));
	i = form[1] == '*' ? 2 : 1;
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	tmp = find_index(form[i]);
	return (zeropadend(list, form, tmp, mode) - i);
}

int	checkneg(va_list *list)
{
	va_list copy;
	int		n;

	va_copy(copy, *list);
	n = va_arg(copy, int);
	va_end(copy);
	if (n < 0)
		return (1);
	return (0);
}

int	zeropadend(va_list *list, const char *form, int tmp, int mode)
{
	if (tmp == 21)
		return (zeropadpercent(mode, list, form));
	if (tmp >= 3 && tmp <= 4)
		return (zeropaddec(mode, list, form));
	if (tmp == 5)
		return (zeropadnbru(mode, list, form));
	if (tmp == 6)
		return (zeropadhex(mode, list, form));
	if (tmp == 7)
		return (zeropadhexc(mode, list, form));
	return (0);
}

int	zeropadnbru(int mode, va_list *list, const char *form)
{
	unsigned int	nb;
	int				len;
	int				ret;

	if (mode >= 1)
		len = va_arg(*list, int);
	else
		len = ft_atoi(form + 1);
	if (mode == 2 || mode == -1)
		va_arg(*list, int);
	if (len < 0)
		return (starleftpad(list, form, -len, 3) - 1);
	nb = va_arg(*list, unsigned int);
	ret = len;
	while (len-- > ft_numlen(nb, 10))
		write(1, "0", 1);
	ft_putnbru_fd(nb, 1);
	if (ret >= ft_numlen(nb, 10))
		return (ret);
	else
		return (ft_numlen(nb, 10));
}

int	zeropadhex(int mode, va_list *list, const char *form)
{
	unsigned int	nb;
	int				len;
	int				ret;

	if (mode >= 1)
		len = va_arg(*list, int);
	else
		len = ft_atoi(form + 1);
	if (mode == 2 || mode == -1)
		va_arg(*list, int);
	if (len < 0)
		return (starleftpad(list, form, -len, 6) - 1);
	nb = va_arg(*list, unsigned int);
	ret = len;
	while (len-- > ft_numlen(nb, 16))
		write(1, "0", 1);
	ft_putnbrbase_fd(nb, "0123456789abcdef", 1);
	if (ret >= ft_numlen(nb, 16))
		return (ret);
	else
		return (ft_numlen(nb, 16));
}

int	zeropadhexc(int mode, va_list *list, const char *form)
{
	unsigned int	nb;
	int				len;
	int				ret;

	if (mode >= 1)
		len = va_arg(*list, int);
	else
		len = ft_atoi(form + 1);
	if (mode == 2 || mode == -1)
		va_arg(*list, int);
	if (len < 0)
		return (starleftpad(list, form, -len, 7) - 1);
	nb = va_arg(*list, unsigned int);
	ret = len;
	while (len-- > ft_numlen(nb, 16))
		write(1, "0", 1);
	ft_putnbrbase_fd(nb, "0123456789ABCDEF", 1);
	if (ret >= ft_numlen(nb, 16))
		return (ret);
	else
		return (ft_numlen(nb, 16));
}
