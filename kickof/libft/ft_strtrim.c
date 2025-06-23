#include <stdlib.h>  // malloc
#include <stddef.h>  // size_t

size_t	ft_strlen(const char *s)
{
	size_t len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

// ft_strtrim: A function that trims leading and trailing characters from a string based on a set of characters.
// It returns a new dynamically allocated string with the trimmed content, or NULL if memory allocation fails
// or if the input string is NULL. The function iterates through the input string to find the first and last
// characters that are not in the set, and then copies the substring between these indices into a new string.
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start = 0;
	size_t	end;
	char	*trimmed;
	size_t	i = 0;

	if (!s1 || !set)
		return (NULL);

	end = ft_strlen(s1);

	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	while (end > start && ft_is_in_set(s1[end - 1], set))
		end--;

	trimmed = (char *)malloc(end - start + 1);
	if (!trimmed)
		return (NULL);

	while (start < end)
		trimmed[i++] = s1[start++];
	trimmed[i] = '\0';

	return (trimmed);
}
#include <stdio.h>

int	main(void)
{
	char *s = " \t\nHello World! \n\t ";
	char *trimmed = ft_strtrim(s, " \n\t");

	if (trimmed)
	{
		printf("Trimmed: '%s'\n", trimmed);  // Output: 'Hello World!'
		free(trimmed);
	}
	return (0);
}
