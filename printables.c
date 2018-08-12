#include "ft_printf.h"

void	print_num(t_components *m)
{
	m->buff = ft_strncat(m->buff, m->num, m->len);
	//m->ret += write(m->fd, m->num, m->len);
}

void	print_char(t_components *m, char c, int z)
{
	//m->ret += z;
	char tmp[z + 1];

	ft_memset(tmp, c, z);
	tmp[z] = '\0';
	m->buff = ft_strcat(m->buff, tmp);
}
