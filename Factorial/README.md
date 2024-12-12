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
<pre>n! = n x (n - 1)!<br>or<br>F(n) = F(n) x F(n - 1)!</pre>
We can create a function that has one parameter
<br>
<pre>typedef unsigned long long ullint;<br>ullint factorial(ullint baseNumber);</pre>
Where 
<ul>
  <li>
    <strong>ullint</strong> is a custom data type for <strong>unsigned long long</strong>, which is used to store large numbers (64-bit integer).
  </li>
  <li>
    <strong>factorial</strong> is the name of the function
  </li>
  <li>
    <strong>(ullint baseNumber)</strong> is the parameter of the function, which is the number you want to calculate the factorial of.
  </li>
</ul>
<br>
So, looking from the formula, the inside of the function would be:
<br><br>
<pre>ullint factorial(ullint baseNumber){
    if (baseNumber == 0){
        return 1;
    }
    return baseNumber * factorial(baseNumber-1);
}</pre>
<pre>if (baseNumber == 0){
    return 0;
}
</pre>
This part is a base case.
In recursion we need a condition that stops the function from calling itself endlessly.
<br>
By definition, 0! = 1. So if the input baseNumber is 0, the function return 1 directly, and no further recursion happends.