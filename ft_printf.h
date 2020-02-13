/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:47:44 by asaboure          #+#    #+#             */
/*   Updated: 2020/02/11 21:11:33 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

int		find_index(char c);
void	chr(va_list *list);
void	str(va_list	*list);
void	ptr(va_list *list);
void	nbr(va_list *list);
void	nbrhex(va_list *list);

#endif
