#include <stdio.h>

#include "ft_printf.h"

int main(){
    char word[10] = "apple";
    printf("%zu\n", ft_strlen(word));

    ft_printf("ccdd", 'a', 'z', 9, 99);
}