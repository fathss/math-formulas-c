#include <stdio.h>

main (){

    puts("A program for calculating the greatest common divisor (GCD)");
    puts("Enter the input (a b)");
    int a, b, mod;
    printf(">>>> ");
    scanf("%d %d", &a, &b);

    while (b != 0){
        mod = a % b;
        a = b;
        b = mod;
    }

    printf(">>>> %d", a);

    return 0;
}
