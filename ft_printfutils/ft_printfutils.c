/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:39:24 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/12 15:45:58 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	strnumlen(const char *form)
{
	int i;

	i = 0;
	while (form[i] >= '0' && form[i] <= '9')
		i++;
	return (i);
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
