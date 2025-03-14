#include <unistd.h>

int main()
{
    char c = 'z';

    while (c >= 'a')
    {
        if (c % 2 == 0) // ASCII değeri çiftse, küçük harf olarak yaz
            write(1, &c, 1);
        else // ASCII değeri tekse, büyük harfe çevirip yaz
        {
            char upper = c - 32; // Küçük harfi büyüğe çevir
            write(1, &upper, 1);
        }
        c--; // Bir önceki harfe geç
    }
    write(1, "\n", 1); // Yeni satır ekle

    return 0;
}




/*
#include <unistd.h>
int main(){
    char z = 'z';
    int i = z - 'z';
    char c;
    while (z>='a')
    {
        if(i%2 == 0)
            write(1, &z, 1);
        else{
            c = z - 32;
            write(1, &c, 1);
        }
        i++;
        z--;
    }
    
}
*/