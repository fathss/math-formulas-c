#include <stdio.h>

typedef unsigned long long ullint;
ullint factorial(ullint);

int main(){

    int n;
    puts("A program for generating a factorial of a non-negative integer n, denoted by n!");
    puts("Due to the limitations of data types in C, this program can only represent 0! to 20! factorial");
    printf(">>>> ");
    scanf("%d", &n);
    printf(">>>> %llu", factorial(n));

    return 0;
}

ullint factorial(ullint baseNumber){
    if (baseNumber == 0 || baseNumber == 1){
        return 1;
    }
    return baseNumber * factorial(baseNumber-1);
}
