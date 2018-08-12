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
	int a;
	a = ft_printf("f: %s\n", "This is a string");
	printf("f: %d, d: %d\n", a, printf("p: %s\n", "This is a string"));
	return (0);
}
