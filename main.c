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
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>


int	main()
{
	
	/*char	t[4];

	t[0] = '1';
	t[1] = '\0';
	t[2] = '2';
	t[3] = '\n';
	write(1, t, 4);
	i*/
	printf("%d:%d\n", ft_printf("f:%c\n", -0), printf("p:%c\n", -0));

	/*unsigned short r = (short)~0U>>1;
	unsigned long long aa = -r - 1;
	ft_printf("unsigned long long	aa = %llu sizeof aa = %lu\n\n",aa,sizeof(aa)); */
	//ft_printf("%s%oBAGEL", "NOAHS", 42);
	
	//int a;
	//a = ft_printf("f: %s %d\n", "This is a string", 42);
	//printf("f: %d, d: %d\n", a, printf("p: %s %d\n", "This is a string", 42));
	return (0);
}
