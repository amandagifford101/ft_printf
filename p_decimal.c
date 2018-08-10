/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_decimal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 21:03:10 by agifford          #+#    #+#             */
/*   Updated: 2018/08/10 14:06:14 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(long long int value, int base)
{
	char *str;
	unsigned long long int n;
	int len;
	int i;

	n = ABS(value);
	len = 1;
	i = 0;
	while (n && (len++))
		n /= base;
	if (value == 0)
		len = 2;
	len += IS_NEG(value);
	str = (char*)malloc(sizeof(char) * len);
	if (IS_NEG(value))
		str[i] = '-';
	i = len - 1;
	n = ABS(value);
	while (--i >= IS_NEG(value))
	{
		str[i] = HEX[n % base];
		n /= base;
	}
	str[len - 1] = '\0';
	return (str);
}

static void	format(t_components *m)
{
	m->num = ft_itoa_base(m->arg.i, 10);
	m->len = ft_strlen(m->num);

	if (!m->prec && !m->width)
		print_nbr(m);
	else if (m->width && m->prec && m->prec > m->width)
		print_dom(m);
	else if (m->width && m->prec && m->width > m->prec)
		print_
}

void	p_decimal(t_components *m)
{
	sign_sign(m); //in sign_sign and unsign make sure you are completely checking CAP types as well
	format(m);
	if (CHECK_MINUS(m->flags))
	{
		if ((CHECK_PLUS(m->flags) && !m->zero && m->ret++) //double check what you think p->sign represents
			ft_putchar_fd(m->sign, m->fd);
		if (m->prec != -1)
			print_char(m, ' ', m->spaces); //print_char only prints spaces when necessary? sometimes zero?
		else
			(CHECK_ZERO(m->flags)) ? print_char(m, '0', m->spaces)
								: print_char(m, ' ', m->spaces);
			print_char(m, '0', p->zeroes);
			print_num(m);
		}
	}
}
