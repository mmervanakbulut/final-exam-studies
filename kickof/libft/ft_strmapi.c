#include <stdlib.h>  // malloc
#include <stddef.h>  // size_t

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;
	while (s[i])
		i++;
	return (i);
}

// ft_strmapi: A function that applies a function to each character of a string,
// returning a new dynamically allocated string with the results.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*result;

	if (!s || !f)
		return (NULL);

	len = ft_strlen(s);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);

	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
#include <stdio.h>

char	to_upper_even(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32); // sadece çift index’teki harfleri büyüt
	return (c);
}

int	main(void)
{
	char *original = "libftproject";
	char *mapped = ft_strmapi(original, to_upper_even);

	if (mapped)
	{
		printf("Original: %s\n", original);
		printf("Mapped  : %s\n", mapped);
		free(mapped);
	}
	return (0);
}
