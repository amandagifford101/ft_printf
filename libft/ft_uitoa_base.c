#include "libft.h"

char	*ft_uitoa_base(unsigned long long int value, int base)
{
	unsigned long long int	n;
	char					*ret;
	int						len;
	int						i;

	n = ABS(value);
	len = 1;
	i = 0;
	while (n && (len++))
		n /= base;
	if (value == 0)
		len = 2;
	len += IS_NEG(value);
	ret = (char*)malloc(sizeof(char) * len);
	if (IS_NEG(value))
		ret[i] = '-';
	i = len - 1;
	n = ABS(value);
	while (--i >= IS_NEG(value))
	{
		ret[i] = HEX[n % base];
		n /= base;
	}
	ret[len - 1] = '\0';
	return (ret);
}
