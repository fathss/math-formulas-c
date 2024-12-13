#include <stdio.h>

int fibonacci(int);

int main(){

    int n;
    puts("A program for generating a fibonacci sequence up to given number\n");
    puts("Due to repeated calculation in recursive function,\nto avoid huge time complexity, this program only limits the input until the 46th sequence.\n");
    printf(">>>> ");
    scanf("%d", &n);

    if (n > 46){
        puts("Consider using the iterative solution for a sequence that exceeds 46th sequence");
        exit(0);
    }
    
    printf(">>>> ");

    for (int i = 0; i <= n; i++){
        printf("%d ", fibonacci(i));
    }
    return 0;
}

int fibonacci(int num_terms){
    if (num_terms == 0){
        return 0;
    } else if (num_terms == 1){
        return 1;
    } else{
        return fibonacci(num_terms - 1) + fibonacci(num_terms - 2);
    }
}
