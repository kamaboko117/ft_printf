/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:47:44 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/29 19:23:17 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef int(**t_tabfnct)(va_list *, const char *);
t_tabfnct	tabinit(void);
int			ft_printf(const char *form, ...);
int			find_index(char c);
int			chr(va_list *list, const char *form);
int			str(va_list	*list, const char *form);
int			ptr(va_list *list, const char *form);
int			nbr(va_list *list, const char *form);
int			nbrhex(va_list *list, const char *form);
int			nbrhexcaps(va_list *list, const char *form);
int			zeropad(va_list *list, const char *form);
int			zeropaddec(int mode, va_list *list, const char *form);
int			zeropaddecend(int nb, int ret, int i);
int			zeropadhex(int mode, va_list *list, const char *form);
int			zeropadhexc(int mode, va_list *list, const char *form);
int			dotpad(va_list *list, const char *form);
int			dotpadnbr(va_list *list, int len);
int			dotpadhex(va_list *list, int len);
int			dotpadhexc(va_list *list, int len);
int			leftpad(va_list *list, const char *form);
int			ft_putmaxstr(const char *s, int len);
int			leftpadend(int ret, int i, int len, const char *form);
int			pad(va_list *list, const char *form);
int			paddec(va_list *list, int len, int j);
int			padhex(va_list *list, int len);
int			padhexc(va_list *list, int len);
int			percent(va_list *list, const char *form);
int			padpercent(const char *form, int len);
int			zeropadpercent(int mode, va_list *list, const char *form);
int			padstr(va_list *list, int len);
int			strnumlen(const char *form);
int			paddotpad(va_list *list, const char *form, int len);
int			dotpadstr(va_list *list, int len);
int			paddotpadstr(va_list *list, const char *form, int len);
int			paddotpaddec(int nb, const char *form, int len);
int			nbru(va_list *list, const char *form);
int			pdphex(unsigned int nb, const char *form, int len, int mode);
int			padptr(va_list *list, int len);
int			dotpadptr(va_list *list, int len);
int			paddotpadptr(unsigned int nb, const char *form, int len);
int			padchr(va_list *list, int len);
int			starleftpad(va_list *list, const char *form, int len, int tmp);
int			zeropadend(va_list *list, const char *form, int tmp, int mode);
int			padelse(va_list *list, const char *form, int len, int i);
int			pdpstar(va_list *list, const char *form, int len);
int			pdpshex(unsigned int nb, int len, int zl);
int			pdpshexc(unsigned int nb, int len, int zl);
int			pdpsdec(int nb, int len, int zl);
int			pdpsstr(va_list *list, int len, int size);
int			padnbru(va_list *list, int len);
int			zeropadnbru(int mode, va_list *list, const char *form);
int			dotpadnbru(va_list *list, int len);
int			leftpadpercent(int len, int j, const char *form);
int			starleftpdp(va_list *list, const char *form, int len);
int			checkpercentpad(const char *form);
int			freetabend(va_list *list, int (**f)(va_list *, const char*),
						int len, int i);
int			freetab(int (**f)(va_list *, const char*), int len, int i);
int			checkzeropad(va_list *list, const char *form, int j, int mode);
int			paddotpadu(unsigned int nb, const char *form, int len);
int			checkneg(va_list *list);
int			pdpsu(unsigned int nb, int len, int zl);
#endif
