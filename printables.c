#include "ft_printf.h"

void	print_num(t_components *m)
{
	m->ret += write(m->fd, m->num, m->len);
}

void	print_char(t_components *m, char c, int z)
{
	m->ret += z;
	while (z > 0)
	{
		ft_putchar_fd(c, m->fd);
		z--;
	}
}
