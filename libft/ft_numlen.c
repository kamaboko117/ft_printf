/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:09:43 by asaboure          #+#    #+#             */
/*   Updated: 2020/02/11 19:39:14 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_numlen(long n, int base)
{
	int	ret;

	ret = 1;

	while (n >= base || n <= -base)
	{
		ret++;
		n = n / base;
	}
	return (ret);
}
