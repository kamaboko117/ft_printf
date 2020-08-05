/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeropad1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 21:03:44 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/05 18:29:06 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	zeropad(va_list *list, const char *form)
{
	int i;
	int tmp;
	int	mode;

	i = 1;
	if (form[1] == '.')
		dotpad(list, form + 1);
	if (form[1] == '-')
		return (leftpad(list, form + 1) - 1);
	while (form[i] >= '0' && form[i] <= '9')
		if (form[1 + i++] == '.')
			return (pad(list, form + 1) - 1);
	i = form[1] == '*' ? 2 : 1;
	mode = form[1] == '*' ? 1 : 0;
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	tmp = find_index(form[i]);
	return (zeropadend(list, form, tmp, mode));
}

int	zeropadend(va_list *list, const char *form, int tmp, int mode)
{
	if (tmp == 21)
		return (zeropadpercent(mode, list, form));
	if (tmp >= 3 && tmp <= 5)
		return (zeropaddec(mode, list, form));
	if (tmp == 6)
		return (zeropadhex(mode, list, form));
	if (tmp == 7)
		return (zeropadhexc(mode, list, form));
	return (0);
}

int	zeropaddec(int mode, va_list *list, const char *form)
{
	int	nb;
	int	len;
	int	ret;
	int	i;

	if (mode == 1)
		len = va_arg(*list, int);
	else
		len = ft_atoi(form + 1);
	if (len < 0)
		return (starleftpad(list, form, -len, 3) - 1);
	nb = va_arg(*list, int);
	ret = len - 1;
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
	return (zeropaddecend(nb, ret, i) - strnumlen(form + 1) - mode);
}

int	zeropadhex(int mode, va_list *list, const char *form)
{
	int	nb;
	int	len;
	int	ret;
	int	i;

	if (mode == 1)
		len = va_arg(*list, int);
	else
		len = ft_atoi(form + 1);
	if (len < 0)
		return (starleftpad(list, form, -len, 6) - 1);
	nb = va_arg(*list, int);
	ret = len - ft_numlen(len, 16) - 1;
	i = 1;
	while (len-- > ft_numlen(nb, 16))
		write(1, "0", 1);
	ft_putnbrbase_fd(nb, "0123456789abcdef", 1);
	if (ret >= ft_numlen(nb, 16) - i - 1)
		return (ret);
	else
		return (ft_numlen(nb, 16) - i - 1);
}

int	zeropadhexc(int mode, va_list *list, const char *form)
{
	int	nb;
	int	len;
	int	ret;
	int	i;

	if (mode == 1)
		len = va_arg(*list, int);
	else
		len = ft_atoi(form + 1);
	if (len < 0)
		return (starleftpad(list, form, -len, 7) - 1);
	nb = va_arg(*list, int);
	ret = len - ft_numlen(len, 16) - 1;
	i = 1;
	while (len-- > ft_numlen(nb, 16))
		write(1, "0", 1);
	ft_putnbrbase_fd(nb, "0123456789ABCDEF", 1);
	if (ret >= ft_numlen(nb, 16) - i - 1)
		return (ret);
	else
		return (ft_numlen(nb, 16) - i - 1);
}
