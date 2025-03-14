#include <unistd.h>
int main(int argc, char **argv){
    if (argc > 1){
        while (*argv[1] != '\0')
        {
            write(1, &*argv[1], 1);
            argv[1]++;
        }
    }
    write(1, "\n", 1);
    
}

/*

write(1, &*argv[1], 1);
argv[1]++;
"Burada argv[1]++ ifadesi, argv[1] dizisinin bellekteki adresini değiştirmeye çalışıyor. Ancak argv[1] bir char * olduğu için bunu değiştirmek programın başka yerlerinde hatalara yol açabilir. Bunun yerine, geçici bir değişken kullanarak doğru bir şekilde işleyebiliriz."


#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        char *str = argv[1]; // İlk argümanı bir pointer değişkene atayalım
        while (*str)
        {
            write(1, str, 1);
            str++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

*/