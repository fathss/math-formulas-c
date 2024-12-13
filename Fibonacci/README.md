# Fibonacci sequence
In mathematics, the Fibonacci sequence is a sequence which each number is the sum of the two numbers that precede it. Numbers that are part of the Fibonacci sequence are known as **Fibonacci numbers**, commonly denoted _Fn_. 
<br><br>
The 20th sequence starting from 0th is:
```
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181 
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
And so the final answer is 3.
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
