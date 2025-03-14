#include <unistd.h>

int main()
{
    int i = 9;
    char c;

    while (i >= 0)
    {
        c = '0' + i; // Sayıyı karaktere çevir
        write(1, &c, 1);
        i--;
    }
    write(1, "\n", 1); // Yeni satır ekleyelim
    return 0;
}
