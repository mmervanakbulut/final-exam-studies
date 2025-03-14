#include <unistd.h>

int main(void)
{
    char c = 'a';
    char upper;
    while (c <= 'z')
    {
        if ((c - 'a') % 2 == 0) // Tek sıra: Küçük harf
            write(1, &c, 1);
        else // Çift sıra: Büyük harf
        {
            upper = c - 32; // Küçük harfi büyük harfe çevirme
            write(1, &upper, 1);
        }
        c++;
    }
    write(1, "\n", 1);
    return (0);
}
