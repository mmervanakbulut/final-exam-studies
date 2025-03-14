#include <unistd.h>
int main(int argc, char **argv){
    if(argc != 2)
        return (write(1, "a\n", 2));
    if(argc == 2){
        while (*argv[1] != '\0')
        {
            if(*argv[1] == 'a')
                return(write(1, "a\n", 2));
            argv[1]++;
        }
    }
    return write(1, "\n", 1);
    
}