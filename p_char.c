#include "ft_printf.h"

void	null_print(t_components *m)
{
	char	t[1];
	
	t[0] = '\0';
	if (m->arg.c == '\0')
	{
		ft_putstr(m->buff);
		write(1, &t, 1);
		m->buff = ft_strnew(0);
	}	
	else
		print_char(m, m->arg.c, 1);
}

void	p_char(t_components *m)
{
	m->arg.c = (char)va_arg(m->args, int);
	m->len = 1;
	m->spaces = m->width - m->len;
	if (CHECK_MINUS(m->flags))
	{
		null_print(m);
		if (m->spaces > 0)
			print_char(m, ' ', m->spaces);
	
	}
	else
	{
		if (m->spaces > 0)
			print_char(m, ' ', m->spaces);
		null_print(m);		
	}
}

