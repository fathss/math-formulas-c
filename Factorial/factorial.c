#include <stdio.h>

typedef long long int llint;
llint factorial(llint);

int main(){

    int n;
    puts("A program for generating a factorial of a non-negative integer n, denoted by n!");
    puts("However, due to the limitations of data types in C, this program can only represent 0 <= n <= 20");
    puts("Input the factorial number");
    printf(">>>> ");
    scanf("%d", &n);
    printf(">>>> %lld", factorial(n));

    return 0;
}

llint factorial(llint baseNumber){
    if (baseNumber == 0 || baseNumber == 1){
        return 1;
    }
    return baseNumber * factorial(baseNumber-1);
}
