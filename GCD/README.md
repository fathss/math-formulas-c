# Greatest Common Divisor (GCD)
In mathematics, the **greates common divisor (GCD)**, also known as **greates common factor (GCF)**, of two or more integers,
which are not all zero, is the largest positive integer that divides each of the integers. For two integers _x, y_, the greatest common divisor of _x_ and _y_ is denoted gcd(x, y).
<br><br>
For example, the number 54 can be expressed as a product of two integers in several different ways:
<pre>54 x 1 = 27 x 2 = 18 x 3 = 9 x 6</pre>
Thus the complete list of divisors of 54 is 1, 2, 3, 6, 9, 18, 27, 54. Similarly, 
the divisors of 24 are 1, 2, 3, 4, 6, 8, 12, 24. The numbers that these two lists have _in common_ are the _common divisors_ of 54 and 24, that is,
<pre>1, 2, 3, 6.</pre>
Of these, the greatest is 6, so it is the _greatest common divisor_:
<pre>gcd(54, 24) = 6.</pre>
Computing all divisors of the two numbers in this way is usually not efficient, especially for large numbers that have many divisors.
<br>
For a much more efficient method we'll be using the euclidean algorithm.

### Eucledian Algorithm
The method introduced by Euclid for computing greatest common divisors is based on the fact that, given two positive integers _a_ and _b_ such that _a_ > _b_, 
the common divisors of _a_ and _b_ are the same as the common divisors of _a_ – _b_ and _b_.
<br>
This method can be very slow if one number is much larger than the other. 
<br><br>
A more efficient method is the _Euclidean algorithm_, 
a variant in which the difference of the two numbers _a_ and _b_ is replaced by the remainder of the Euclidean division (also called _division with remainder_) of _a_ by _b_.
<br><br>
Denoting this remainder as _a_ mod _b_, the algorithm replaces (_a_, _b_) with (_b_, _a_ mod _b_) repeatedly until the pair is (_d_, 0), where _d_ is the greatest common divisor.
<br><br>
The formula is as follows:
<pre>gcd(a, b) -> gcd(b, a mod b)</pre>
For example, to compute ```gcd(54, 24)```, the computation is as follows:
<pre>gcd(54, 24) ->  gcd(24, 54 mod 24) = gcd(24, 6)
<br>            ->  gcd(6, 24 mod 6) = gcd(6, 0).
</pre>
This gives ```gcd(54, 24) = 6.```

## How it works in C
We can implement the formula above using a while loop. Where if _b_ is not 0 the loop will continue until so.
```c
while (b != 0){
    mod = a % b;
    a = b;
    b = mod;
}
```
### Explanation
1. You start with two numbers ```a``` and ```b``` (e.g., ```a = 54```, ```b = 24```).
2. ```while (b != 0)```. The loop continues as long as ```b``` is not zero. When ```b``` becomes zero, the loop stops, and the value of ```a``` is the GCD.
3. ```mod = a % b```. This calculates the remainder when ```a``` is divided by ```b```.For example, ```54 % 24 = 6```. (6 is the remainder).
4. ```a = b```. The value of ```b``` is now assigned to ```a```. For example, ```a``` now becomes 24.
5. ```b = mod```. The remainder (```mod```) becomes the new value of ```b```. For example, ```b``` now becomes 6.
6. Repeat the process until ```b``` becomes 0.
