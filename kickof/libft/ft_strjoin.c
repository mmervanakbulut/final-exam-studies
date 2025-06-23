#include <stdlib.h>  // malloc
#include <stddef.h>  // size_t

size_t	ft_strlen(const char *s)
{
	size_t i = 0;
	while (s[i])
		i++;
	return (i);
}

// ft_strjoin: A function that concatenates two strings into a new dynamically allocated string.
// It returns a pointer to the new string, or NULL if memory allocation fails.
// The new string is the result of appending s2 to s1. If either s1 or s2 is NULL, it returns NULL.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i = 0, j = 0;
	size_t	len1, len2;

	if (!s1 || !s2)
		return (NULL);

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);

	joined = (char *)malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);

	while (i < len1)
	{
		joined[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}
#include <stdio.h>

int main(void)
{
	char *s1 = "Hello, ";
	char *s2 = "world!";
	char *result = ft_strjoin(s1, s2);

	if (result)
	{
		printf("Joined: %s\n", result);  // "Hello, world!"
		free(result);
	}
	return 0;
}
