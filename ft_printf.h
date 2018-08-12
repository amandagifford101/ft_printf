/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agifford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:38:55 by agifford          #+#    #+#             */
/*   Updated: 2018/08/09 21:35:35 by agifford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef union
{
	char		c;
	char		*s;
	wchar_t		*w;
	intmax_t 	i;
	uintmax_t	u;
	void		*v;
}				t_types;

typedef struct		s_components
{
	char 	*fmt;
	char	*buff;
	va_list	args;
	t_types	arg; //this is the union, what you pul out of va list
	int		i;
	int		a; // Is this a solution or locally in funct?
	int		fd;
	int		ret;
	int		flags;
	int		width;
	int		prec;
	char	*num;
	int		spaces;
	int		zeroes;
	int		len;
	char	sign;

}					t_components;

enum flags {
	plus = 1,
	minus = 1 << 1,
	hash = 1 << 2,
	zero = 1 << 3,
	space = 1 << 4,
	h = 1 << 5,
	hh = 1 << 6,
	l = 1 << 7,
	ll = 1 << 8,
	z = 1 << 9,
	j = 1 << 10,
	s = 1 << 11,
	ss = 1 << 12,
	p = 1 << 13,
	d = 1 << 14,
	dd = 1 << 15,
	i = 1 << 16,
	o = 1 << 17,
	oo = 1 << 18,
	u = 1 << 19,
	uu = 1 << 20,
	x = 1 << 21,
	xx = 1 << 22,
	c = 1 << 23,
	cc = 1 << 24,
	percent = 1 << 25
};

# define ASSIGN_PLUS(X) (X |= plus)
# define ASSIGN_MINUS(X) (X |= minus)
# define ASSIGN_HASH(X) (X |= hash)
# define ASSIGN_ZERO(X) (X |= zero)
# define ASSIGN_SPACE(X) (X |= space)
# define ASSIGN_H(X) (X |= h)
# define ASSIGN_HH(X) (X |= hh)
# define ASSIGN_L(X) (X |= l)
# define ASSIGN_LL(X) (X |= ll)
# define ASSIGN_Z(X) (X |= z)
# define ASSIGN_J(X) (X |= j)
# define ASSIGN_S(X) (X |= s)
# define ASSIGN_SS(X) (X |= ss)
# define ASSIGN_P(X) (X |= p)
# define ASSIGN_D(X) (X |= d)
# define ASSIGN_DD(X) (X |= dd)
# define ASSIGN_I(X) (X |= i)
# define ASSIGN_O(X) (X |= o)
# define ASSIGN_OO(X) (X |= oo)
# define ASSIGN_U(X) (X |= u)
# define ASSIGN_UU(X) (X |= uu)
# define ASSIGN_X(X) (X |= x)
# define ASSIGN_XX(X) (X |= xx)
# define ASSIGN_C(X) (X |= c)
# define ASSIGN_CC(X) (X |= cc)
# define ASSIGN_PERCENT(X) (X |= percent)


# define CHECK_PLUS(X) ((X & plus) ? (1) : (0))
# define CHECK_MINUS(X) ((X & minus) ? (1) : (0))
# define CHECK_HASH(X) ((X & hash) ? (1) : (0))
# define CHECK_ZERO(X) ((X & zero) ? (1) : (0))
# define CHECK_SPACE(X) ((X & space) ? (1) : (0))
# define CHECK_H(X) ((X & h) ? (1) : (0))
# define CHECK_HH(X) ((X & hh) ? (1) : (0))
# define CHECK_L(X) ((X & l) ? (1) : (0))
# define CHECK_LL(X) ((X & ll) ? (1) : (0))
# define CHECK_Z(X) ((X & z) ? (1) : (0))
# define CHECK_J(X) ((X & j) ? (1) : (0))
# define CHECK_S(X) ((X & s) ? (1) : (0)) 
# define CHECK_SS(X) ((X & ss) ? (1) : (0))
# define CHECK_P(X) ((X & p) ? (1) : (0))
# define CHECK_D(X) ((X & d) ? (1) : (0))
# define CHECK_DD(X) ((X & dd) ? (1) : (0))
# define CHECK_I(X) ((X & i) ? (1) : (0))
# define CHECK_O(X) ((X & o) ? (1) : (0))
# define CHECK_OO(X) ((X & oo) ? (1) : (0))
# define CHECK_U(X) ((X & u) ? (1) : (0))
# define CHECK_UU(X) ((X & uu) ? (1) : (0))
# define CHECK_X(X) ((X & x) ? (1) : (0))
# define CHECK_XX(X) ((X & xx) ? (1) : (0))
# define CHECK_C(X) ((X & c)  ? (1) : (0))
# define CHECK_CC(X) ((X & cc) ? (1) : (0))
# define CHECK_PERCENT(X) ((X & percent) ? (1) : (0))

int		ft_printf(const char *fmt, ...);
void	main_station(t_components *m);
void	buff_it(t_components *m);
void	init(t_components *m, int fd, char *fmt);
void	re_init(t_components *m);
void	arg_out(t_components *m);
void	print_arg(t_components *m);
void		assign_flags(t_components *m);
int			is_digit(int c);
void		field_width(t_components *m);
int			is_prec(t_components *m);
void		get_prec(t_components *m);
int			is_len_mod(t_components *m);
void		len_mod(t_components *m);
void		assign_type(t_components *m);
void		flag_flipper(t_components *m);
void		p_octal(t_components *m);
void		string_it(t_components *m);
void		p_wide_string(t_components *m);
void		p_pointer(t_components *m);
void		p_decimal(t_components *m);
void    	p_undecimal(t_components *m);
void 		p_hex(t_components *m);
void 		p_char(t_components *m);
void		sign_sign(t_components *m);
void		print_num(t_components *m);
void		print_char(t_components *m, char c, int z);
void		unsign(t_components *m);


/*
** Helpers
*/
void print_bits(int n);



#endif
