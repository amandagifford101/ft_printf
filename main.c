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
	ft_printf("%c", 42);
	ft_printf("Kashim a %c histoires à raconter", 1001);
	ft_printf("Il fait au moins %c\n", -8000);
	ft_printf("%c", -0);
	ft_printf("%c", 0);
	ft_printf("%c\n", INT_MAX);
	ft_printf("%c\n", 'c');
	ft_printf("%c\n", '\n');
	ft_printf("%c", 'l');
	ft_printf("%c", 'y');
	ft_printf("%c", ' ');
	ft_printf("%c", 'e');
	ft_printf("%c", 's');
	ft_printf("%c", 't');
	ft_printf("%c", ' ');
	ft_printf("%c", 'f');
	ft_printf("%c", 'a');
	ft_printf("%c", 'n');
	ft_printf("%c", 't');
	ft_printf("%c", 'a');
	ft_printf("%c", 's');
	ft_printf("%c", 't');
	ft_printf("%c", 'i');
	ft_printf("%c", 'q');
	ft_printf("%c", 'u');
	ft_printf("%c", 'e');
	ft_printf("%c\n", '!');
	ft_printf("%c\n", '\r');
	ft_printf("%c\n", '\t');

	printf("%c", 42);
	printf("Kashim a %c histoires à raconter", 1001);
	printf("Il fait au moins %c\n", -8000);
	printf("%c", -0);
	printf("%c", 0);
	printf("%c\n", INT_MAX);
	printf("%c\n", 'c');
	printf("%c\n", '\n');
	printf("%c", 'l');
	printf("%c", 'y');
	printf("%c", ' ');
	printf("%c", 'e');
	printf("%c", 's');
	printf("%c", 't');
	printf("%c", ' ');
	printf("%c", 'f');
	printf("%c", 'a');
	printf("%c", 'n');
	printf("%c", 't');
	printf("%c", 'a');
	printf("%c", 's');
	printf("%c", 't');
	printf("%c", 'i');
	printf("%c", 'q');
	printf("%c", 'u');
	printf("%c", 'e');
	printf("%c\n", '!');
	printf("%c\n", '\r');
	printf("%c\n", '\t');


	/*unsigned short r = (short)~0U>>1;
	unsigned long long aa = -r - 1;
	ft_printf("unsigned long long	aa = %llu sizeof aa = %lu\n\n",aa,sizeof(aa)); */
	//ft_printf("%s%oBAGEL", "NOAHS", 42);
	
	//int a;
	//a = ft_printf("f: %s %d\n", "This is a string", 42);
	//printf("f: %d, d: %d\n", a, printf("p: %s %d\n", "This is a string", 42));
	return (0);
}
