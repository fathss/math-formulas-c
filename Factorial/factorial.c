#include <stdio.h>

typedef long long int llint;
llint factorial(llint);

int main(){

    int number;
    puts("A program for generating a factorial of a non-negative integer n, denoted by n!");
    puts("However, due to the limitations of data types in C, this program can only represent 0 <= n <= 20");
    puts("Input the factorial number");
    printf(">>>> ");
    scanf("%d", &number);
    printf(">>>> %lld", factorial(number));

    return 0;
}

llint factorial(llint x){
    if (x == 0 || x == 1){
        return 1;
    }
    return x * factorial(x-1);
}
