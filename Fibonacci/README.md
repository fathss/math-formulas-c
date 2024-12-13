# Fibonacci sequence
In mathematics, the Fibonacci sequence is a sequence which each number is the sum of the two numbers that precede it. Numbers that are part of the Fibonacci sequence are known as **Fibonacci numbers**, commonly denoted _Fn_. 
<br><br>
The 20th sequence starting from 0th is:
```
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765 
```

Many writers begin the sequence with 0 and 1, although some authors start it from 1 and 1. The program i create will begin from 0.
<br><br>
The Fibonacci numbers may be defined by the recurrence relation
<pre>F0 = 0, F1 = 1,</pre>
and
<pre>Fn = F(n - 1) + F(n - 2)</pre>
for n > 1

## How it works in C
We can implement the fibonacci sequence in C with both iteratively or recursively. Both with it's own pros and cons.

### 1. Recursive solution
In recursive solution, we'll be using the recursive function. Much like how we do it in factorial, this function will call itself until it meets the base case.
<br><br>
From the formula above we know that:
<pre>Fn = F(n - 1) + F(n - 2)</pre>
for n > 1, and
<pre>F0 = 0, F1 = 1</pre>
We can easily replicate this formula into a function like this:
```c
int fibonacci(int num_terms){
    if (num_terms == 0){
        return 0;
    } else if (num_terms == 1){
        return 1;
    } else{
        return fibonacci(num_terms - 1) + fibonacci(num_terms - 2);
    }
}
```
So, to explain it i'll split it into three parts.
#### 1. Function definition
```c
int fibonacci(int num_terms);
```
```Fibonacci``` is the name of the function.<br>
```int num_terms``` is the parameter (input) that represents the position in the Fibonacci sequence for which we want the value.
#### 2. Base cases
```c
if (num_terms == 0) {
    return 0;
} else if (num_terms == 1) {
    return 1;
}
```
These two if's condition define the base cases for the recursion.<br><br>
If ```num_terms == 0```, the function returns 0 (the 0th fibonacci number).<br>
If ```num_terms == 1```, the function returns 1 (the 1th fibonacci number).
#### 3. Recursive case
```c
return fibonacci(num_terms - 1) + fibonacci(num_terms - 2);
```
For any number greater than 1, the function calls itself twice:<br><br>
It calculates the Fibonacci number at position ```num_terms - 1```.<br>
It calculates the Fibonacci number at position ```num_terms - 2```.<br><br>
These two values are added together to give the Fibonacci number at current position.
```c
return fibonacci(num_terms - 1) + fibonacci(num_terms - 2);
```
Is the same as
<pre>Fn = F(n - 1) + F(n - 2)</pre>
<br>

This is how the function works if you call ```fibonacci(4)``` (4th sequence):<br>
<ol>
  <li>fibonacci(4) = fibonacci(3) + fibonacci(2)</li>
  <li>fibonacci(3) = fibonacci(2) + fibonacci(1)</li>
  <li>fibonacci(2) = fibonacci(1) + fibonacci(0)</li>
  <li>
    Now, the base cases are reached:
    <ul>
      <li>fibonacci(1) = 1</li>
      <li>fibonacci(0) = 0</li>
    </ul>
  </li>
  <li>
    Substituting back:
    <ul>
      <li>fibonacci(2) = 1 + 0 = 1</li>
      <li>fibonacci(3) = 1 + 1 = 2</li>
      <li>fibonacci(4) = 2 + 1 = 3</li>
    </ul>
  </li>
</ol>
<br>
And so the final number is 3.
<br><br>

You noticed that in ```recursive_fibonacci.c``` file, there is a for loop inside the main function
```c
for (int i = 0; i <= n; i++){
    printf("%d ", fibonacci(i));
}
```
This loop calculates and prints the Fibonacci numbers from the 0th term up to the nth term using the ```fibonacci``` function.
<br><br>
And now for the pros and cons of this type of solution
##### Pros
<ul>
  <li>Simplicity and clarity</li>
  <li>No External Data Structures Needed</li>
</ul>

##### Cons

<ul>
  <li>Exponential time complexity, meaning that to compute fibonacci(40), it computes fibonacci(39), and fibonacci(38), and so on until the base cases</li>
  <li>Recursive calls add overhead due to function call stack management. This makes it slower than iterative or optimized approaches for large inputs.</li>
</ul>

### 2. Iterative solution
In iterative solution will mainly use a for loop.
<br><br>
For better understanding we'll be looking at the F4 fibonacci number starting from F0.
<pre>0, 1, 1, 2, 3</pre>
So, to get F2 we have to add F1 and F0
<pre>F2 = F1 + F0</pre>
![image](https://github.com/user-attachments/assets/b07e33a8-05b6-4c20-89ca-91259ee0d39c)
<br><br>
and to get F3 we have to add F2 and F1
<pre>F3 = F2 + F1</pre>
![image](https://github.com/user-attachments/assets/1cc4197a-acbe-4599-bcf1-5c022253d2c1)
<br><br>
and to get F4 we have to add F3 and F2
<pre>F4 = F3 + F2</pre>
![image](https://github.com/user-attachments/assets/523b253c-e60f-40fc-888a-0d3cde7bfedd)
<br><br>
Notice anything? Any pattern?
<br>
For F2, F3, and F4. Let's assume that the two numbers that preceed it as a and b. And the result as c
<br>
![image](https://github.com/user-attachments/assets/0f5f3287-4842-4724-9107-862caac5e0e6)
<br><br>
So, to get to F4 we first start from 0 and 1 because we already know that F0 = 0 and F1 = 1.<br>
Then on the next step, we do ```a + b``` to get ```c``` which is F2.<br>
After that, ```a``` moved one tile, and ```b``` moved one tile.<br>
So now ```a = 1``` and ```b = 1```.<br>
```a + b``` = ```2``` which is F3.<br>
Then, ```a``` moved one tile and ```b``` moved one tile.<br>
Now ```a = 1``` and ```b = 2```.<br>
```a + b = 3``` which is F4.
<br><br>
This pattern can be replicated using a for loop:
```c
ullint a = 0, b = 1, c;

for (int i = 0; i <= n; i++){
        if (i == 0){
            printf("%llu ", a);
        } else if (i == 1){
            printf("%llu ", b);
        } else{
            c = a + b;
            printf("%llu ", c);
            a = b;
            b = c;
        }
    }
```
Let's break it down into 3 parts:
#### 1. Variable declarations
```c
ullint a = 0, b = 1, c;
```
```ullint``` is a custom data type for ```unsigned long long```, which is used to store large numbers (64-bit integer).<br>
```a``` and ```b``` are initialized as 0 and 1 respectively. These represent the first two terms of the Fibonacci sequence.<br>
```c``` is declared to hold the sum of ```a``` and ```b``` (next Fibonacci number).

#### 2. For loop
```c
for (int i = 0; i <= n; i++){
```
The for loop runs from ```i = 0``` to ```i = n```, where ```n``` is the nth sequence.<br>
```i``` acts as the counter for the sequence, where ```i``` represents the current Fibonacci term's position.

#### 3. Conditional logic
Inside the loop, the program handles the Fibonacci sequence calculation and printing based on the value of ```i```:

##### Case 1: First Sequence (i = 0)
```c
if (i == 0){
    printf("%llu ", a);
}
```
If ```i``` is 0, it simply prints the first fibonacci number (```a```), which is 0.

##### Case 2: Second Sequence (i = 1)
```c
else if (i == 1){
    printf("%llu ", b);
}
```
If ```i``` is 1, it prints the second fibonacci number (```b```), which is 1.

##### Case 3: Remaining sequence (i > 1)
```c
else {
    c = a + b;
    printf("%llu ", c);
    a = b;
    b = c;
}
```
For ```i``` > 1 it calculates the next fibonacci number.<br>
```c = a + b``` Adds the two previous numbers (```a``` and ```b```) to get the next Fibonacci number (```c```).<br>
```printf("%llu ", c)``` Prints the current fibonacci number (```c```).<br>
```a``` Shift to ```b```.<br>
```b``` Shift to ```c```.<br><br>
So, if n = 4, the loop runs from ```i``` = 0 to ```i``` = 4, and the output is
```
0 1 1 2 3
```
Step-by-step explanation:<br>
1. ```i``` = 0, prints 0 (```a = 0```).<br>
2. ```i``` = 1, prints 1 (```b = 1```).<br>
3. ```i``` = 2, computes ```c = a + b = 0 + 1 = 1```, prints 1 (```c = 1```), updates ```a``` = ```b``` = 1, ```b``` = ```c``` = 1.<br>
4. ```i``` = 3, computes ```c = a + b = 1 + 1 = 2```, prints 2 (```c = 2```), updates ```a``` = ```b``` = 1, ```b``` = ```c``` = 2.<br>
5. ```i``` = 4, computes ```c = a + b = 1 + 2 = 3```, prints 3 (```c = 3```), updates ```a``` = ```b``` = 2, ```b``` = ```c``` = 3.<br>

So, the final number is 3.
<br><br>
And now for the pros and cons of iterative solution:
##### Pros
<ul>
    <li>Linear time complexity, The iterative approach has a time complexity of O(n), where n is the position of the Fibonacci number to calculate. It calculates each term exactly once without redundant computations, unlike the recursive approach.
    </li>
    <li>Low memory usage.</li>
    <li>Faster execution.</li>
</ul>

##### Cons
<ul>
    <li>Limited readability.</li>
    <li>Scalability, while iterative methods are efficient for reasonably large n, they may still be slow for extremely large inputs due to limitations in computational power or number representation.
    </li>
</ul>
