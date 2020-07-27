#include <stdio.h>

#include "includes/ft_printf.h"

int main(){
    char word[10] = "apple";
    printf("%zu\n", ft_strlen(word));

    ft_printf("dd%-f");
}