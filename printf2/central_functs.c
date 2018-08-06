#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	t_components *m;

	init(&m, 1, (char*)fmt);
	va_start(m.args, fmt);
	main_station(&m);
	va_end(m.args);
	return (m.ret);
}

void	main_station(t_components *m)
{
	int a;

	a = 0;
	while (m->fmt[m->i])
	{
		if (m->fmt[m->i] == %)
		{
			arg_out(m, a); 
			print_arg(m, a);
			re_init(m);
			a -= m->fmt[m->i]; 
		}
		else
		{
			buff_it(m, a);
			a++;
		}
	}			
}

void	buff_it(t_components *m, int a)
{
	char *temp;
	temp = ft_strcat(m->buff, ft_strsub(m->fmt, a, 1)); //one char added to m->buff
	free(m->buff);
	m->buff = temp;
	m->ret++;
}

// difference between static void and void?

void	flag_flipper(t_components *m, int a) // I dont want to send a around unnecc.
{
	assign_flags(m); //must move to next spot for all these
	if (is_digit(m))
		field_width(m); 
	if (is_prec(m))
		get_prec(m);
	if (is_len_mod(m))
		len_mod(m); 
	assign_type(m);
}
		
void	assign_flags(t_components *m)
{
	while (m->fmt[m->i] == '0' || m->fmt[m->i] == ' ' || 
		m->fmt[m->i] == '#'|| m->fmt[m->i] == '-' || m->fmt[m->i] == '+')
	{
		if (m->fmt[m->i] == '+')
			ASSIGN_PLUS(m->flags);
		else if (m->fmt[m->i] == '-')
			ASSIGN_MINUS(m->flags);
		else if (m->fmt[m->i] == '#')
			ASSIGN_HASH(m->flags);
		else if (m->fmt[m->i] == '0')
			ASSIGN_ZERO(m->flags);
		else if (m->fmt[m->i] == ' ')
			ASSIGN_SPACE(m->flags);
		m->i++;
	}
}

void	assign_type(t_components *m)
{
	
	if (m->fmt[m->i] == 's')
		ASSIGN_S(m->flags);
	else if (m->fmt[m->i] == 'S')
		ASSIGN_SS(m->flags);
	else if (m->fmt[m->i] == 'p')
		ASSIGN_P(m->flags);
	else if (m->fmt[m->i] == 'd')
		ASSIGN_D(m->flags);
	else if (m->fmt[m->i] == 'D')
		ASSIGN_DD(m->flags);
	else if (m->fmt[m->i] == 'i')
		ASSIGN_I(m->flags);
	else if (m->fmt[m->i] == 'o')
		ASSIGN_O(m->flags);
	else if (m->fmt[m->i] == 'O')
		ASSIGN_OO(m->flags);
	else if (m->fmt[m->i] == 'u')
		ASSIGN_U(m->flags);
	else if (m->fmt[m->i] == 'U')
		ASSIGN_UU(m->flags);
	else if (m->fmt[m->i] == 'x')
		ASSIGN_X(m->flags);
	else if (m->fmt[m->i] == 'X')
		ASSIGN_XX(m->flags);
	else if (m->fmt[m->i] == 'c')
		ASSIGN_C(m->flags);
	else if (m->fmt[m->i] == 'C')
		ASSIGN_CC(m->flags);
	else if (m->fmt[m->i] == '%')
		ASSIGN_PERCENT(m->flags);
	m->i++;

}

void	field_width(t_components *m)
{
	if (is_digit(m->fmt[m->i]))
		m->fd = atoi(m->fmt + m->i);
	while (is_digit(m->fmt))
		m->i++;
}
		
int	is_prec(t_components *m)
{
	if (m->fmt[m->i] == '.')
	{
		m->i++;
		return (1);
	}
	return (0);
}	

void get_prec(t_components *m)
{
	if (is_digit(m->fmt[m->i]))
		m->prec = atoi(m->fmt + m->i);  //add error check for else (if no digit after '.') ??
	while (is_digit(m->fmt[m->i]))
		m->i++;
}	

void	len_mod(t_components *m)
{
	if (m->fmt[m->i] == 'h' && m->fmt[m->i + 1] == 'h'i && (m->i += 2))
		ASSIGN_HH(m->flags);    
	else if (m->fmt[m->i] == 'h' && (m->i++))
		ASSIGN_H(m->flags);	
	else if (m->fmt[m->i] == 'l' && m->fmt[m->i + 1] == 'l'(m->i += 2))
		ASSIGN_LL(m->flags);
	else if (m->fmt[m->i] == 'l' && (m->i++))
		ASSIGN_L(m->flags);
	else if (m->fmt[m->i] == 'j' && (m->i++))
		ASSIGN_J(m->flags);
	else if (m->fmt[m->i] == 'z' && (m->i++))
		ASSIGN_Z(m->flags);
}

/* This way of catching m->ret as we go through parsing seems to work, but I still need to think about how I will** implement the counting of a from main_station throughout the parser... I think I can do it with pointer logic ** at the end of the entire string however I may need to be sending it in to all of these funtions as well. Anoth*/ er option is to put it as a piece of my struct and be resetting it there which I think might be the best. 


void	arg_out(t_components *m)
{
	m->i++;
	assign_flags(m);
	if (CHECK_S(m->flags)) // fix all of these
		string_it(m);
	else if (m->type == 'S')
		p_wide_string(m);
	else if (m->type == 'p')
		p_pointer(m);
	else if (m->type == 'd' || p->type == 'D' || p->type == 'i')
		p_decimal(m);
	else if (m->type == 'o' || m->type == 'O')
		p_octal(m);
	else if (m->type == 'u' || m->type == 'U')
		p_undecimal(m);
	else if (m->type == 'x' || m->type == 'X')
		p_hex(m);
	else if (p->type == 'c' || p->type == 'C')
		p_char(m);
	else if (p->type == '%')
		p->ret = write(p->fd, "%", 1);
}

void	string_it(t_components *m)
{
	if (m->l_mod && m->l_mod[0] == 'l')
	{
		p_wide_string(m);
		return;
	}
	m->arg.s = va_arg(m->args, char*); //this is pulling out a char* from va_list and plopping it in your union
	if (!m->args.s && m->ret = write(fd, "(NULL)", 6))
		return;
	p->str_len = ft_strlen(m->args.s)
	if (CHECK_MINUS(m->flags)) // minus means left alligned
	{
		print_string(m);
		print_spaces_(m);
	}
	else
	{
		print_spaces(m);
		print_string(m);
	}
}



 void	p_wide_string(t_components *m)
{
	if ()
}	
		

	
