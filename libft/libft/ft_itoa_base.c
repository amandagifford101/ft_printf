#include "libft.h"

char	*ft_itoa_base(long long int value, int base)
{
	char *str;
	unsigned long long int n;
	int len;
	int i;

	n = ABS(value);
	len = 1;
	i = 0;
	while (n && (len++))
		n /= base;
	if (value == 0)
		len = 2;
	len += IS_NEG(value);
	str = (char*)malloc(sizeof(char) * len);
	if (IS_NEG(value))
		str[i] = '-';
	i = len - 1;
	n = ABS(value);
	while (--i >= IS_NEG(value))
	{
		str[i] = HEX[n % base];
		n /= base;
	}
	str[len - 1] = '\0';
	return (str);
}

