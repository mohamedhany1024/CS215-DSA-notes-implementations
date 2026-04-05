Two types of sorting algos
1. Quadratic Sorters (Selection Sort, Insertion Sort, Bubble Sort)
2. Subquadratic (QuickSort, Merge Sort, Shell Sort, Heap Sort)
## Time Complexity

|         | Selection | Insertion | Bubble | Shell      | Merge      | Quick                                   |
| ------- | --------- | --------- | ------ | ---------- | ---------- | --------------------------------------- |
| worst   | O(n^2)    | O(n^2)    | O(n^2) | O(n^2)     | O(n logn)  | O(n^2)                                  |
| best    | O(n^2)    | O(n )     | O(n)   | O(n log n) | O(n log n) | O(n log(n))                             |
| average | O(n^2)    | O(n^2)    | O(n^2) | O(n^1.5)   | O(n log n) | O(n log(n)) (depending on pivot choice) |
## Memory Complexity
|            | Selection | Insertion | Bubble | Shell | Merge | Quick |
| ---------- | --------- | --------- | ------ | ----- | ----- | ----- |
| Complexity | O(1)      | O(1)      | O(1)   | O(1)  | O(n)  | O(1)  |

## Comparison based sorting as Decision Trees (very important, look in lecture slides too)

We can represent a comparison based sorting algo as a decision tree.
- The terminal nodes in this tree represent results of the algorithm as permutations of the array to be sorted
- the levels represent the steps needed to reach one of the results

an n element array has n! possible orderings (permutation without replacement)

since no.terminal = $2^{i}$ = n! (where i is the index of the last level) (see [[BinaryTreeBasics]])
$i = log_2(n!)$

so, given our decision tree, we can infer that a comparison based sorting algo, can reach the result in worst case scenario in log(n!)

log(n!) belongs to O(n log n)
![[Pasted image 20260312174715.png]]

we can see that graphically, after $n_0 = 1, c=1$ g(n) is always higher than f(n), and thus log (n!) belongs to O(n log(n))

if we want to do this analytically
1. find intersection points
	1. n log(n) = log(n!)
	2. $log(n^n) = log(n!)$
	3. $n^n = n!$
	4. at n = 1, $n^n = 1, n! = 1$
2. test the function n log(n) - log(n!)
3. ![[Pasted image 20260312182452.png]]
4. so, g(n) is greater than f(n) on the interval ]1, +inf)

## Sorting In linear Time
### 1. Counting Sort
Non-comparison based sort
 we'll need 3 arrays: input A, output B and C
 1. Initialize C with 0's (C is a frequency array of A), size is max(A)
 2. iterate over C and record frequency of A
 3. apply prefixSum to C
4. ```
    for i = n; i>= 2; i--
	    B(C[A[i]]) = A[i]
	    C[A[i]] -= 1
    ```
#### Advantages
- Sorting in O(n+m) time where n is no elems in A, and m is max(A)
- Stable Sorting Algo (order of repeated elems is preserved)
#### Disadvantages
- Sorting takes O(n+m) memory
- if range is too big, array size will be huge.
	- e.g: A = [1, 100000] --> C will be huge, lots of wasted space
- doesn't support -ve or float values

### Radix Sort
instead of applying count sort on the whole number, we will iteratively apply it from the least significant digit to the most significant
given that each digit ranges from 0 to 9
our array C won't be too big as in the case of pure Count Sort




