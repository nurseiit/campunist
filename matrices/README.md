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
