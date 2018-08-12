#include "ft_printf.h"

static void	format(t_components *m)
{
	m->num = ft_uitoa_base(m->arg.u, 8);
	m->len = ft_strlen(m->num);
	if (CHECK_HASH(m->flags) && m->num[0] != '0')
		m->zeroes++;
	if (m->prec > m->len + m->zeroes)
		m->zeroes = m->prec - m->len;
	if (CHECK_MINUS(m->flags))
		m->spaces = m->width - (m->zeroes + m->len);
	else
		(CHECK_ZERO(m->flags)) ? (m->zeroes += m->width - (m->zeroes + m->len))
			: (m->spaces = m->width - (m->zeroes + m->len));
} 

void	 p_octal(t_components *m)
{
	unsign(m);
	format(m);
	if (CHECK_MINUS(m->flags))
	{
		print_char(m, '0', m->zeroes);
		print_num(m);
		print_char(m, ' ', m->spaces);
	}
	else
	{
		print_char(m, ' ', m->spaces);
		print_char(m, '0', m->zeroes);
		print_num(m);
	}
}



