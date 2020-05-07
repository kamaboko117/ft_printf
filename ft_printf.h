/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:47:44 by asaboure          #+#    #+#             */
/*   Updated: 2020/05/07 18:46:39 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *form, ...);
int	find_index(char c);
int	chr(va_list *list, const char *form);
int	str(va_list	*list, const char *form);
int	ptr(va_list *list, const char *form);
int	nbr(va_list *list, const char *form);
int	nbrhex(va_list *list, const char *form);
int	nbrhexcaps(va_list *list, const char *form);
int	(**tabinit(void))(va_list *, const char*);
int	zeropad(va_list *list, const char *form);
int	dotpad(va_list *list, const char *form);
int	leftpad(va_list *list, const char *form);

#endif
