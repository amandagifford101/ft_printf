#include "ft_printf.h"

void	print_num(t_components *m)
{
	m->buff = ft_strncat(m->buff, m->num, m->len);
	//m->ret += write(m->fd, m->num, m->len);
}

void	print_char(t_components *m, char c, int z)
{
	//m->ret += z;
	char tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	while (z > 0)
	{
		m->buff = ft_strcat(m->buff, tmp);
		z--;
	}
}
