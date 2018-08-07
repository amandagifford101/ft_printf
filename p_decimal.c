/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_decimal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:49:46 by agifford          #+#    #+#             */
/*   Updated: 2018/08/06 16:07:10 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_decimal(t_components *m)
{
	if (CHECK_D(m->flags))
		p->l_mod = "l";
	p_convert(m);
	format(m);
	if (CHECK_MINUS(m->flags))
	{
		(p->sign && !CHECK_ZERO(m->flags) && p->ret++)
			ft_putchar_fd(p->sign, p->fd);
		print_char(p, '0', p->zeroes);
		print_num(p);
		print_char(p, ' ', p->spaces)

