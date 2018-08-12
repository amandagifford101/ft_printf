#include "ft_printf.h"

void	p_char(t_components *m)
{
	m->arg.c = (char)va_arg(m->args, int);
	m->len = 1;
	m->spaces = m->width - m->len;
	if (CHECK_MINUS(m->flags))
	{
		print_char(m, m->arg.c, 1);
		if (m->spaces > 0)
			print_char(m, ' ', m->spaces);
	}
	else
	{
		if (m->spaces > 0)
			print_char(m, ' ', m->spaces);
		print_char(m, m->arg.c, 1);
	}
}

