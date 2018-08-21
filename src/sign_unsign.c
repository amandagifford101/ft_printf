/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 20:19:14 by agifford          #+#    #+#             */
/*   Updated: 2018/08/12 20:24:11 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsign(t_components *m)
{
	if (CHECK_L(m->e_flags))
		m->arg.u = (unsigned long)va_arg(m->args, unsigned long long);
	else if (CHECK_LL(m->e_flags))
		m->arg.u = (unsigned long long)va_arg(m->args, unsigned long long);
	else if (CHECK_H(m->e_flags))
		m->arg.u = (unsigned short)va_arg(m->args, unsigned long long);
	else if (CHECK_HH(m->e_flags))
		m->arg.u = (unsigned char)va_arg(m->args, unsigned long long);
	else if (CHECK_Z(m->e_flags))
		m->arg.u = (size_t)va_arg(m->args, unsigned long long);
	else if (CHECK_J(m->e_flags))
		m->arg.u = (uintmax_t)va_arg(m->args, unsigned long long);
	else
		m->arg.u = (unsigned int)va_arg(m->args, unsigned long long);
}

void	sign_sign(t_components *m)
{
	if (CHECK_LL(m->e_flags))
		m->arg.i = (long long)va_arg(m->args, long long int);
	else if (CHECK_L(m->e_flags))
		m->arg.i = (long)va_arg(m->args, long long int);
	else if (CHECK_H(m->e_flags))
		m->arg.i = (short)va_arg(m->args, long long int);
	else if (CHECK_HH(m->e_flags))
		m->arg.i = (char)va_arg(m->args, long long int);
	else if (CHECK_Z(m->e_flags))
		m->arg.i = (size_t)va_arg(m->args, long long int);
	else if (CHECK_J(m->e_flags))
		m->arg.i = (intmax_t)va_arg(m->args, long long int);
	else
		m->arg.i = (int)va_arg(m->args, long long int);
}
