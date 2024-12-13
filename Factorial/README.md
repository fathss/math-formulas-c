# Factorial formula
In mathematics, the factorial of a non-negative integer _n_, denoted by _n!_, is the product of all positive integers less than or equal to _n_. The factorial of _n_ is also equals to the product of _n_ with the next smaller factorial:
<br>
<pre>n! = n x (n - 1) x (n - 2) x (n - 3) x ... x 3 x 2 x 1</pre>
Which means that:
<pre>n! = n x (n - 1)!</pre>
For example
<pre>5! = 5 x 4! = 5 x 4 x 3 x 2 x 1 = 120</pre>
## How it works in C
This recursive function can easily be implemented in C or any other language that supports a function
<br><br>
From the formula above we know that:
<pre>n! = n x (n - 1)!</pre>
We can create a function that has one parameter
<br>
<pre>typedef unsigned long long ullint;<br>ullint factorial(ullint baseNumber);</pre>
Where ```ullint``` is a custom data type for <strong>unsigned long long</strong>, which is used to store large numbers (64-bit integer).<br>
```factorial``` is the name of the function.<br>
```(ullint baseNumber)``` is the parameter of the function, which is the number you want to calculate the factorial of.
<br><br>
So, looking from the formula, the inside of the function would be:


```
ullint factorial(ullint baseNumber){
    if (baseNumber == 0){
        return 1;
    }
    return baseNumber * factorial(baseNumber-1);
}
```
```
if (baseNumber == 0){
    return 1;
}
```
This part is a base case.
In recursion we need a condition that stops the function from calling itself endlessly.
<br>
By definition, 0! = 1. So if the input baseNumber is 0, the function return 1 directly, and no further recursion happends.

```
return baseNumber * factorial(baseNumber - 1);
```
If <strong>baseNumber</strong> is not 0, the function calculates the factorial by multiplying <strong>baseNumber</strong> by the result of calling <strong>factorial(baseNumber - 1)</strong>
<br><br>
Let's see how it works for calculating 5!:
<br>
Assuming <strong>baseNumber</strong> as n!:
<ol>
  <li>factorial(5)</li>
  <ul>
    <li>5 x factorial(4)</li>
  </ul>
  <li>factorial(4)</li>
  <ul>
    <li>4 x factorial(3)</li>
  </ul>
  <li>factorial(3)</li>
  <ul>
    <li>3 x factorial(2)</li>
  </ul>
  <li>factorial(2)</li>
  <ul>
    <li>2 x factorial(1)</li>
  </ul>
  <li>factorial(5)</li>
  <ul>
    <li>1 x factorial(0)</li>
  </ul>
  <li>factorial(0)</li>
  <ul>
    <li>returns = 1</li>
  </ul>
</ol>
Now, the recursion starts to "unwind" and we get the final result:
<ul>
  <li>factorial(1) = 1 x 1 = 1</li>
  <li>factorial(2) = 2 x 1 = 2</li>
  <li>factorial(3) = 3 x 2 = 6</li>
  <li>factorial(4) = 4 x 6 = 24</li>
  <li>factorial(5) = 5 x 24 = 120</li>
</ul>
<br>
So, the result of 5! is 120
