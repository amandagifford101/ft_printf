/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central_functs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:10:43 by agifford          #+#    #+#             */
/*   Updated: 2018/08/07 14:34:37 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	t_components m;

	init(&m, 1, (char*)fmt);
	va_start(m.args, fmt);
	main_station(&m);
	va_end(m.args);
	return (m.ret);
}

void	main_station(t_components *m)
{
	while (m->fmt[m->i])
	{
		if (m->fmt[m->i] == '%')
		{
			flag_flipper(m); 
			print_arg(m);
		//	re_init(m);
		//	a -= m->fmt[m->i]; 
		}
		else
		{
			buff_it(m);
		//	a++;
		}
	}			
}

void	buff_it(t_components *m)
{
	char *temp;
	temp = ft_strncat(m->buff, m->fmt, 1); //one char added to m->buff
	free(m->buff);
	m->buff = temp;
	m->ret++;
}