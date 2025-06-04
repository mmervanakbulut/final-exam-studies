#include <stdlib.h>

// ft_strdup: A function that duplicates a string by allocating memory for it and copying the content.
// It returns a pointer to the newly allocated string, or NULL if memory allocation fails.
char *ft_strdup(const char *s) {
    size_t len = 0;
    char *copy;
    size_t i = 0;

    while (s[len])
        len++;

    copy = (char *)malloc(len + 1);
    if (!copy)
        return NULL;

    while (i <= len) { // '\0' dahil
        copy[i] = s[i];
        i++;
    }

    return copy;
}

int main(void) {
    const char *original = "Hello, world!";
    char *duplicate = ft_strdup(original);

    if (duplicate) {
        // Test the result
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate); // Unutma, malloc ile ayrılan belleği serbest bırak
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}