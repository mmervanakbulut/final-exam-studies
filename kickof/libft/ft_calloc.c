#include <stdlib.h>

// ft_calloc: A function that allocates memory for an array of nmemb elements of size bytes each,
// initializes all bytes to zero, and returns a pointer to the allocated memory.
void    *ft_calloc(size_t nmemb, size_t size) {
    size_t total;
    size_t i = 0;
    unsigned char *ptr;

    if (nmemb == 0 || size == 0)
        return malloc(1); // Unique pointer

    total = nmemb * size;

    // (Opsiyonel) overflow kontrolü
    if (size != 0 && total / size != nmemb)
        return NULL;

    ptr = (unsigned char *)malloc(total);
    if (!ptr)
        return NULL;

    while (i < total) {
        ptr[i] = 0;
        i++;
    }

    return (void *)ptr;
}

int main(void) {
    // Test ft_calloc
    size_t nmemb = 5;
    size_t size = sizeof(int);
    int *arr = (int *)ft_calloc(nmemb, size);

    if (arr) {
        for (size_t i = 0; i < nmemb; i++) {
            printf("%d ", arr[i]); // Should print 0s
        }
        free(arr);
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}