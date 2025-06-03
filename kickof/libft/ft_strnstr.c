#include <stdio.h>

char    *strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;

    if (!*needle)
        return (char *)haystack;

    while (haystack[i] && i < len)
    {
        if (haystack[i] == needle[0])
        {
            while (needle[j] && haystack[i + j] && (i + j) < len)
            {
                if (haystack[i + j] != needle[j])
                    break;
                j++;
            }
            if (!needle[j])
                return (char *)(haystack + i);
        }
        i++;
    }
    return NULL;
}

int main(void)
{
    const char *haystack = "Hello, world!";
    const char *needle = "world";
    size_t len = 13;

    char *result = strnstr(haystack, needle, len);
    if (result)
        printf("Found: %s\n", result);
    else
        printf("Not found\n");

    return 0;
}