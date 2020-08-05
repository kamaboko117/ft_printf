/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeropad2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:59:56 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/05 18:00:12 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	zeropaddecend(int nb, int ret, int i)
{
	ft_putnbr_fd(nb, 1);
	if (ret >= ft_numlen(nb, 10) - i)
		return (ret);
	else
		return (ft_numlen(nb, 10) - i);
}
