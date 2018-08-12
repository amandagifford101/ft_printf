#include "ft_printf.h"

static void	ft_wstrlen(t_components *m)
{
	size_t i;
	
	i = 0;
	while (m->arg.w[++i] != '\0')
		m->len++;
}

static void	print_wstring(t_components *m)
{
	int i;

	i = -1;
	while (m->arg.w[++i] != '\0' && i <= m->spaces)
		write(m->fd, &m->arg.w[i], 1);
}

static void	print_string(t_components *m)
{
	m->spaces = (m->prec != -1 && m->prec < m->len)
	? (m->prec) : (m->len);
	print_wstring(m);
}

static void	print_spaces(t_components *m)
{
	m->spaces = (m->prec >= 0 && m->prec < m->len)
	 ?	(m->width - m->prec) : (m->width - m->len);
	while (m->spaces > 0)
		write(m->fd, " ", m->spaces);
}

void	p_widestring(t_components *m)
{
	m->arg.w = va_arg(m->args, wchar_t*);
	if (!m->arg.w && write(m->fd, "(null)", 6))
		return;
	ft_wstrlen(m);
	if (CHECK_MINUS(m->flags))
	{
		print_string(m);
		print_spaces(m);
	}
	else
	{
		print_spaces(m);
		print_string(m);
	}
}
