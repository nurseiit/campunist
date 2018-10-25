# Cheatsheet

## Matrix multiplication
Consider two matrices:
1. Matrix **A is (NxK) dimensional**.
2. Matrix **B is (KxM) dimensional**.

*Notice that A's columns and B's rows number are identical!*

Then we define **matrix C = A * B** as:

![Multi](https://github.com/nurseiit/campunist/raw/master/matrices/files/c%3Da*b.png)

Thus, **C is an (NxM) dimensional matrix** and is obtained as follows:
![Formula](https://github.com/nurseiit/campunist/raw/master/matrices/files/multi_formula.png)

### Couple of things to notice:

1. Matrix C has **N * M** elements, each element is computed in **K** steps with given formula 
  
  **=>** we can obtain C in _**O(n * m * k)**_, given A and B;

2. If **N = M = K** (i.e. both A and B have N rows and N columns), then C has N rows and N columns, and can be computed in **O(N^3)**.

### Some useful properties of matrix multiplication:

1. It is **not commutative**: **A * B ≠ B * A** in general case;
2. It is **associative**: **A * B * C = (A * B) * C = A * (B * C)** in case A * B * C exists;
3. If you have matrix with *N* rows and *N* columns, then multiplying it by **I_N** gives the same matrix, i. e. **I_N * A = A * I_N = A**. 

Where **I_N** is a matrix with N rows and N columns of such form:

![I_N](https://github.com/nurseiit/campunist/raw/master/matrices/files/i_n.png)

## Matrix exponentiation
Suppose we need to find some square matrix **A** to the power of **P** or **A^P**.

We can do so via:
```python
function matpow_naive(A, P):
  result = I_N
  for i = 1..P:
    result = result * A
  return result
```

Which runs in **O(P x N^3)**: we multiply NxN matrix P times.


But, we can do it much faster via BinPow as follows:

```python
function matBinPow(A, P):
  result = I_N
  while P > 0:
    if P % 2 == 1:
      result = result * A
    A = A * A
    P = P / 2
  return result
```

Which runs in **O(log(P) x N^3)**.

## Applications of Matrix Exponentiation
### Finding *Nth* Fibonacci number:
Fibonacci numbers, **F_N** are defined as:
1. **F_0 = F_1 = 1**
2. **F_i = F_{i-1} + F_{i-2}** for _**i >= 2**_.

We are to find **F_N** some modulo **M**, where *N < 10^18* and *M = 10^9 + 7*.

#### Trivial Solution...
Skipped.
#### Faster Solution
Here is when matrices get involved. 

Suppose we have a vector (matrix with one row and several columns) of **(F_{i - 2}, F_{i - 1})** and we want to multiply it by some matrix, so that we get **(F_{i - 1}, F_i)**. 

Let’s call this matrix **M**:

