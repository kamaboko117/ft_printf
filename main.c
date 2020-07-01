/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 18:48:45 by asaboure          #+#    #+#             */
/*   Updated: 2020/05/14 22:23:51 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	//void	*cursed = malloc(42);
	//char	*s = "nique ta race jo";
	//int		x = 713752;
	//char	*form = NULL;
	printf("[%d]\n", ft_printf("%5i", 75));
	printf("[%d]\n", printf("%5i", 75));

//	ft_printf("kamaboko117 %.10X kamaboko117\n", x);
//	printf("kamaboko117 %.10X kamaboko117\n", x);
}
