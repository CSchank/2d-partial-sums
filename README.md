# 2d-partial-sums
C library for quickly computing the 2D partial sums of a matrix. Some examples are provided as well.

## Using the code 
`#include "partialsums.h"` once files are in the correct directory. Compile your code while linking `partialsums.o`.

## Functions
#### unsigned long int *generate_lookup(unsigned int *A, int m, int n)
Returns a pointer to the 2D partial sum matrix of size m by n (same size as original). Generated in O(m*n) time with m and n
being the width and height of the matrix.

#### unsigned long int query_sum(unsigned long int *A, int n, int x1, int y1, int x2, int y2)
Used to query the partial sum matrix generated prior. Returns the sum of an area in O(1) time.
 - (`x1`, `y1`) is the top-left corner of the requested area
 - (`x2`, `y2`) is the bottom-right corner of the requested area
 - `n` is the number of columns in the matrix

## Running examples
Run `make all` in the directory to make the two examples.

## License
Code is licensed under the [CC BY 4.0 license](https://creativecommons.org/licenses/by/4.0/).
