#include <stdlib.h>  // malloc
#include <string.h>  // size_t

size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i])
		i++;
	return (i);
}

// ft_substr: A function that extracts a substring from a given string.
// It takes a string, a starting index, and a length, and returns a new dynamically
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);

	s_len = ft_strlen(s);

	// start dizinin uzunluğundan büyükse, boş string döneriz
	if (start >= s_len)
	{
		char *empty = (char *)malloc(1);
		if (empty)
			empty[0] = '\0';
		return empty;
	}

	// Kopyalanacak gerçek uzunluk s_len - start kadar olabilir
	if (len > s_len - start)
		len = s_len - start;

	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);

	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';

	return (sub);
}
#include <stdio.h>

int main(void)
{
	char *s = "Hello, World!";
	char *result = ft_substr(s, 7, 5);  // "World"
	if (result)
	{
		printf("Substring: %s\n", result);
		free(result);
	}
	return 0;
}
