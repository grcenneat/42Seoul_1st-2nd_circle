#include <stdio.h>

#include "includes/ft_printf.h"

int main(){

    ft_printf("%0*.*d\n", -2, -2, -12);
    printf("%0*.*d\n", -2, -2, -12);
    ft_printf("%5.p\n", NULL);
    printf("%5.p\n", NULL);
    ft_printf("%-16.p\n", NULL);
    printf("%-16.p\n", NULL);
    ft_printf("%0*u\n", -4, 198);
    printf("%0*u\n", -4, 198);
    ft_printf("%0*.*x\n", -4, -4, 0);
    printf("%0*.*x\n", -4, -4, 0);
    ft_printf("%0*x\n", -4, 198);
    printf("%0*x\n", -4, 198);
    ft_printf("%5%\n");
    printf("%5%\n");
    return 0;
}