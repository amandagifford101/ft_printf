#include "ft_printf.h"

void	print_num(t_components *m)
{
	m->buff = ft_strncat(m->buff, m->num, m->len);
}

void	print_char(t_components *m, char c, int z)
{
	int	j;
	int	i;

	i = ft_strlen(m->buff);
	j = 0;
	while (j < z)
	{
		m->buff[i + j] = c;
		j++;
	}
	m->buff[i + j] = '\0';
}
