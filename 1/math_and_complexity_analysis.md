
## 1. Logarithms
- Logarithmic function is the inverse of exponential function
- Growth slows down as input increases
- $a^{log_a (x)} = x$, $log_a(a^x) = x$
- $log(a^b) = b log(a)$
- $log (xy) = log(x) + log(y)$
- $log(x/y) = log(x) - log(y)$
- $log(1/y) = log(y^{-1}) = - log(y)$
- $log_a(b) = log (b) / log (a) = Ln (b) / Ln (a) = log_2(b) / log_2(a)$    "change of base"

![[Pasted image 20260308163615.png]]
A graph demonstrating the growth of the log2 function
## 2.1 Series
### 2.1.1 Arithmetic Series
- A summation of an arithmetic sequence where there is a common difference d between each consecutive terms
- a, a+d, a+2d, a+3d, ..., a+(n-1)d
- $d = a_i - a_{i-1}$
- first term is $a_1$
- ith term is $a_1 + (i-1)d$ 
- sum of first n terms $S_n = n/2(a_1 + l)$ , where l is the last term.           (1)
- if we define l as $l = a_n = a_1 + (n-1)d$       (2)
- then substitute in (1)
- $S_n = n/2(2a_1 + (n-1)d)$


- to derive (2)
- suppose $S = a_1, a_2, a_3, ..., a_n-1$
- and S also equals $a_{n-1}, a_{n-1}, ..., a_1$
- if we add them together
- $2S = a_1 + a _{n-1}, a_2 + a_{n-2}, a_3 + a{n-3}$
- notice how all the terms are equal. e.g: (5+1, 4+2, 3+3, 2+4, ...), there are n of these terms
- so, $2S = n(a_1 + a{n-1}), S = n/2 (a_1 + a_{n-1})$
- 

### 2.1.2 Geometric Series
- A Summation of a Geometric sequence, where there is a common ratio r between each consecutive term
- $(a, ar, ar^2, ar^3, ..., ar^{n-1})$
- $r = ar^n / ar^{n-1}$
- $t_n = ar^{n-1}$
- $S_n = a (1-r^n) / (1-r)$ (finite series)    (1)
- when | r | < 1 --> converges, when | r | >= 1 --> diverges
- $S_n = a/(1-r)$ when the series is infinite and converges, i.e: when | r | < 1


- to derive (1)
- let $rS_n = ar + ar^2 + ar^3+...+ar^n$
- $S_n = a + ar + ar^1 + ... + ar^{n-1}$
- if we subtract them
- $S_n - rS_n = a - ar^n$   the two series are mostly exactly the same, except for the first elem of $S_n$ and the last element of $rS_n$ so everything in the middle cancels out
- $S_n(1-r) = a(1-r^n)$
- $S_n = a(1-r^n)/(1-r)$
## 2.2 Summations
- $\sum_{i=1}^{n} i = {n(n+1)}/2$
-  $\sum_{i=1}^{n} i^2 = {n(n+1)(2n+1)}/6$
- $\sum_{i=0}^{n} 2^i = 2^{n+1} -1$       A special case of the geometric series, where, a = 1, r = 2
- $\sum_{i=1}^{n} 1/ 2^i = 1 - (1/2^n)$   A special case of the geometric series, where, a = 1/2, r = 1/2
- $\sum_{i=1}^{n} i / 2^i = 2 - (n+2)/2^n$

## 2.3 Proof Techniques
### 2.3.1 Proof By Contradiction
1. We start with a statement 
2. we assume that statement is false
3. we reach a contradictory fact, which makes our assumption wrong, thus proving the original statement

### 2.3.2 Proof By Induction
1. We start by proving "base case", we test the statement against some value (e.g: 1)
2. we assume the statement is
	1. true up to k (strong induction)
	2. true for k (simple induction)
3. we prove that the statement is true for k+1 too
4. This proves it's true for any finite k
### 2.3.3 Proof By Counterexample
- We simply find any case that makes the statement invalid

# 3. Complexity analysis
We measure how much the fundamental operations are executed relative to the problem size.
A fundamental operation is an operation that is most frequently executed, and thus, dominates
e.g: adding 1 to an array of size n, we will do this operation n times
e.g: printing all permutations from two arrays of sizes n, m we will do this operation n * m times

### 3.1 Approximations
as the problem size increases the lower degree terms (terms that don't contribute as much) can be approximated
e.g: T(n) = $3n^2 + 2n + 5$ as n --> inf, T(n) --> 3n^2 --> n^2


### 1. Big-Oh (O): The Ceiling

- **Intuition:** "It doesn't get worse than this."
- **Definition:** An **Upper Bound**. It guarantees that the function will never grow faster than this rate.
- **Example:** If an algorithm is O(n2), it might actually run in O(n) sometimes, but you are promised it will _never_ be as slow as n3.
### 2. Big-Omega (Ω): The Floor

- **Intuition:** "It doesn't get better than this."
- **Definition:** A **Lower Bound**. It guarantees that the algorithm will take _at least_ this much time.
- **Example:** If an algorithm is Ω(n), you know that no matter how lucky you get with the input, you still have to look at every element at least once.
    

### 3. Big-Theta (Θ): The Tight Fit

- **Intuition:** "It grows **exactly** like this."
- **Definition:** A **Tight Bound**. A function is Θ(g(n)) if it is _both_ O(g(n)) and Ω(g(n)).
- **The Difference:** While Big-Oh is a "less than or equal to" (≤) relationship, Theta is like an "equals" (=) relationship for growth rates.

![[Pasted image 20260310170850.png]]
a function f(n) belongs to the Set O(g(n)), if there exists two constants, $c, n_0$ such that
$$0<=f(n)<=cg(n)$$
this means that f(n) never exceeds cg(n) as long as n is big enough(i.e: n>= $n_0$)

- to find $n_0$ we need to find the intersection between f(n) and cg(n) by solving the two equations simultaneously. why? remember in calculus? if two functions intersect, they will always change which one is higher than the other. we want to detect when cg(n) will be higher than f(n). we can detect which area cg(n)is higher than f(n) by probing the intervals of intersection and comparing the two functions, or subtracting f(n) from cg(n) and seeing if the result is +ve or -ve in the intervals bounded by the intersection points.
