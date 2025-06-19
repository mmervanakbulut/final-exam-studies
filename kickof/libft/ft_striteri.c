#include <stddef.h>  // size_t

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
#include <stdio.h>

void	to_upper_odd(unsigned int i, char *c)
{
	if (i % 2 == 1 && *c >= 'a' && *c <= 'z')
		*c = *c - 32; // tek indeksli karakterleri büyüt
}

int	main(void)
{
	char str[] = "libft is fun";
	ft_striteri(str, to_upper_odd);
	printf("Modified: %s\n", str);  // Output: lIbFt Is FuN
	return (0);
}
