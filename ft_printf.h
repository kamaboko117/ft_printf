/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:47:44 by asaboure          #+#    #+#             */
/*   Updated: 2020/04/30 14:38:51 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *form, ...);
int	find_index(char c);
void	chr(va_list *list, const char *form);
void	str(va_list	*list, const char *form);
void	ptr(va_list *list, const char *form);
void	nbr(va_list *list, const char *form);
void	nbrhex(va_list *list, const char *form);
void	nbrhexcaps(va_list *list, const char *form);
void	(**tabinit(void))(va_list *, const char*);
void	zeropad(va_list *list, const char *form);
void	dotpad(va_list *list, const char *form);

#endif
