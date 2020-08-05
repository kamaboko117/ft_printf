/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:39:24 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/05 18:08:34 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../ft_printf.h"

int	strnumlen(const char *form)
{
	int i;

	i = 0;
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	return (i);
}

int	starleftpad(va_list *list, const char *form, int len, int tmp)
{
	int	i;
	int	(**f)(va_list *, const char *);
	int ret;

	f = tabinit();
	i = 1;
	ret = len;
	if (tmp == -1)
		return (0);
	len -= (*f[tmp])(list, form + i);
	return (leftpadend(ret, i, len, form));
}

int	ft_putmaxstr(const char *s, int len)
{
	int	i;
	int	tmp;

	tmp = ft_strlen(s);
	i = 0;
	while (s[i] && i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
	if (tmp <= len)
		return (tmp);
	return (len);
}
