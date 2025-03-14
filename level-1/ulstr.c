#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

    // Check if there is exactly 1 argument (excluding program name)
    if (ac != 2)
    {
        write(1, "\n", 1);
        return 1;
    }
    // Loop through the string
    while (av[1][i] != '\0')
    {
        char c = av[1][i];
        // Convert lowercase to uppercase
        if (c >= 'a' && c <= 'z')
            c -= 32;
        // Convert uppercase to lowercase
        else if (c >= 'A' && c <= 'Z')
            c += 32;
        // Print the modified character
        write(1, &c, 1);
        i++;
    }
    write(1, "\n", 1);
    return 0;
}
