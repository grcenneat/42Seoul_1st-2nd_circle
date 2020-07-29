#include <stdio.h>

#include "includes/ft_printf.h"

int main(){
    char word[10] = "apple";
    int  ret_val;

    printf("%zu\n", ft_strlen(word));

    ret_val = ft_printf("dd%3c", 'z');
    printf("\nreturned value : %d\n", ret_val);

    return 0;
}