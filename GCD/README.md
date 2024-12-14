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
