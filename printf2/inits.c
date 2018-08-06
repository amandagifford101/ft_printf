void	init(t_components *m, int fd, char *fmt)
{
	m->hash = false;
	m->plus = false;
	m->minus = false;
	m->zero = false;
	m->space = false;
	m->i = 0;
//	m->a = 0;
	m->fd = fd; 
	m->ret = 0;
	m->flags = 1;
	m->width = 0;
	m->prec = 0;
	m->fmt = "\0";
	m->buff = "\0";
}

/*go over init with Sean, reasons for the way different things are initialized*/
