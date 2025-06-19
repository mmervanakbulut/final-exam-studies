#include <stdlib.h>  // malloc, free
#include <stddef.h>  // size_t

static size_t	word_count(const char *s, char c)
{
	size_t count = 0;
	int in_word = 0;

	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*malloc_word(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	i = 0;

	word = (char *)malloc(end - start + 1);
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	free_all(char **arr, size_t count)
{
	size_t	i = 0;

	while (i < count)
		free(arr[i++]);
	free(arr);
}

// ft_split: A function that splits a string into an array of words based on a delimiter character.
// It returns a dynamically allocated array of strings, with each string being a word from the original
char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		i = 0, word_i = 0, start = 0;

	if (!s)
		return (NULL);

	result = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!result)
		return (NULL);

	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[word_i] = malloc_word(s, start, i);
			if (!result[word_i++])
			{
				free_all(result, word_i - 1);
				return (NULL);
			}
		}
		else
			i++;
	}
	result[word_i] = NULL;
	return (result);
}
#include <stdio.h>

int	main(void)
{
	char **words = ft_split("  hello 42 network  school ", ' ');
	int i = 0;

	while (words && words[i])
	{
		printf("Word %d: %s\n", i, words[i]);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
