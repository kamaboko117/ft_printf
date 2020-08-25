/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaboure <asaboure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 18:48:45 by asaboure          #+#    #+#             */
/*   Updated: 2020/08/25 18:54:34 by asaboure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	//void	*cursed = malloc(42);
	//void	*cursed2 = malloc(7);
	//char	*s = "nique ta race jo";
	//int		x = 713752;
	//char	*s_hidden = "hi low";
	printf("[%d]\n", printf("dkW%0*.5u%16.5sYA%0.2u%11.0ssR%-.1x", -3, -391222460, NULL, 2147483647, "", -1136856890));
	printf("[%d]\n", ft_printf("dkW%0*.5u%16.5sYA%0.2u%11.0ssR%-.1x", -3, -391222460, NULL, 2147483647, "", -1136856890));
//	while (1);
	
//	ft_printf("kamaboko117 %.10X kamaboko117\n", x);
//	printf("kamaboko117 %.10X kamaboko117\n", x);
}