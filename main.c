/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:32:41 by agifford          #+#    #+#             */
/*   Updated: 2018/08/07 14:32:42 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


int	main()
{
	ft_printf("%s%oBAGEL", "NOAHS", 42);
	
	//int a;
	//a = ft_printf("f: %s %d\n", "This is a string", 42);
	//printf("f: %d, d: %d\n", a, printf("p: %s %d\n", "This is a string", 42));
	return (0);
}
