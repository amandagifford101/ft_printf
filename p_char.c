#include "ft_printf.h"

static void	print_spaces(t_components *m)
{
	m->spaces = m->width - m->len;
	while (m->spaces > 0)
		m->ret = write(1, " ", m->spaces);
}

void	p_char(t_components *m)
{
	m->arg.c = (char)va_arg(m->args, int);
	m->len = 1;
	if (CHECK_MINUS(m->flags))
	{
		print_char(m, m->arg.c, 1);
		print_spaces(m);
	}
	else
	{
		print_spaces(m);
		print_char(m, m->arg.c, 1);
	}
}

