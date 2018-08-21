#include "ft_printf.h"

static void		format(t_components *m)
{
	m->num = ft_uitoa_base(m->arg.i, 10);
	m->len = ft_strlen(m->num);
	if (m->prec > m->len)
		m->zeroes = m->prec - m->len;
	if (m->width > (m->len + m->zeroes))
		m->spaces = m->width - (m->len + m->zeroes);
	if (CHECK_PLUS(m->e_flags))
		m->sign = '+';
	if (CHECK_ZERO(m->e_flags) && CHECK_PLUS(m->e_flags))
		m->spaces--;
	if (CHECK_SPACE(m->e_flags) && m->spaces == 0)
		m->spaces++;
}

void	p_undecimal(t_components *m)
{
	unsign(m);
	format(m);
	if (CHECK_MINUS(m->e_flags))
	{
		print_char(m, '0', m->zeroes);
		print_num(m);
		print_char(m, ' ', m->spaces);
	}
	else
	{
		if (m->prec != -1)
			print_char(m, ' ', m->spaces);
		else
			(CHECK_ZERO(m->e_flags)) ? print_char(m, '0', m->spaces)
				: print_char(m, ' ', m->spaces);
		print_char(m, '0', m->zeroes);
		print_num(m);
	}
}
