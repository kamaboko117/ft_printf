/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 18:48:45 by asaboure          #+#    #+#             */
/*   Updated: 2020/07/03 13:51:38 by asaboure         ###   ########.fr       */
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
	printf("[%d]\n", ft_printf("%5s", "goes over"));
	printf("[%d]\n", printf("%5s", "goes over"));
//	ft_printf("kamaboko117 %.10X kamaboko117\n", x);
//	printf("kamaboko117 %.10X kamaboko117\n", x);
}
