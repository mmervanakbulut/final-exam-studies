#include <stdio.h>
int ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return (i);
}
int main(){
    char str[] = "12345";
    printf("%d", ft_strlen(str));
}