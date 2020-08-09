#include <stdio.h>

#include "includes/ft_printf.h"

int main(){

    ft_printf("%0*.*d\n", -2, -2, -12);
    printf("%0*.*d\n", -2, -2, -12);
    ft_printf("%5.p\n", NULL);
    printf("%5.p\n", NULL);
    ft_printf("%u\n", 0);
    ft_printf("%u\n", 4294967295);
    ft_printf("%u\n", -10);
    ft_printf("%x\n", 15);
    ft_printf("%X\n", 15);
    ft_printf("%30%\n");
    return 0;
}