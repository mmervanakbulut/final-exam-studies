#include <stdlib.h>  // malloc
#include <stddef.h>  // size_t

static size_t	ft_intlen(int n)
{
	size_t	len = 0;
	long	nb = n;

	if (nb <= 0)
	{
		len++;
		nb = -nb;
	}
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

// ft_itoa: A function that converts an integer to a string representation.
// It handles negative numbers and returns a dynamically allocated string.
char	*ft_itoa(int n)
{
	long	nb = n;
	size_t	len = ft_intlen(n);
	char	*str;

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);

	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}

	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
#include <stdio.h>

int	main(void)
{
	int	values[] = {0, -42, 12345, -2147483648, 2147483647};
	for (int i = 0; i < 5; i++)
	{
		char *str = ft_itoa(values[i]);
		if (str)
		{
			printf("%d -> \"%s\"\n", values[i], str);
			free(str);
		}
	}
	return (0);
}
