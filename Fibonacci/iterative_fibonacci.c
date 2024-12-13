#include <stdio.h>

typedef unsigned long long ullint;

int main(){

    int n;
    puts("A program for generating a fibonacci sequence up to given number\n");
    puts("Due to the limitations of data types in C, this program only limits the input until the 93th sequence.\n");
    printf(">>>> ");
    scanf("%d", &n);
    if (n > 93){
        puts("Over exceeding the limit");
        exit(0);
    }
    printf(">>>> ");

    ullint a = 0, b = 1, c;

    for (int i = 0; i <= n; i++){
        if (i == 0){
            printf("%llu ", a);
        } else if (i == 1){
            printf("%llu ", b);
        } else{
            c = a + b;
            a = b;
            b = c;
            printf("%llu ", b);
        }
    }

    return 0;
}
