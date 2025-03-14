#include <unistd.h>
int main(int argc, char **argv)
{
    char *str;
    if(argc > 1){
        str = argv[argc -1];
        while (*str != '\0'){
            write(1, str, 1);
            str++;
        } 
    }
    write(1,"\n",1);
}