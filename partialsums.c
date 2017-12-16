/*
 * C library computing the partial sums of a 2D matrix in O(m*n) time.
 * Query operations run in constant time.
 *
 * Author: Christopher W. Schankula
 * Last updated: December 16th, 2017
 * Code is licensed under the CC BY 4.0 license.
 *
 * THE CODE PROVIDED HEREIN IS PROVIDED "AS-IS"
 * THE AUTHOR ASSUMES NO RESPONSBILITY OR WARRANTY
 * FOR USE OF THE CODE PROVIDED HEREIN
 * EXTENSIVE TESTING OF THIS CODE IS REQUIRED
 * TO ENSURE ITS CORRECTNESS AS PART OF THE INTENDED
 * APPLICATION THEREOF
 */

#include <stdlib.h>
#include <stdio.h>
#include "partialsums.h"

/* 
 * Generates the lookup table for a given matrix with m rows and n columns. 
 * Adapted from user rolfl's O(n) algorithm: 
 * https://codereview.stackexchange.com/questions/42906/partial-sums-of-two-dimensional-array
 */
unsigned long int *generate_lookup(unsigned int *A, int m, int n){
	unsigned long int *B = malloc(m*n*sizeof(unsigned long int));
	for (int j = 0; j < m; j++){
		for (int i = 0; i < n; i++){
			unsigned long int abovesum = j > 0 ? *(B + (j - 1) * n + i) : 0;
	   		unsigned long int leftsum = i > 0 ? *(B + j * n + i - 1) : 0;
			unsigned long int aboveleftsum = (i > 0 && j > 0) ? *(B + (j - 1) * n + i - 1) : 0;
			int val = *(A + j * n + i);

			*(B + j * n + i) = val 
							 + aboveleftsum 
							 + (leftsum - aboveleftsum)
							 + (abovesum - aboveleftsum);
		}
	}
	return B;
}

/* 
 * Queries a 2D partial-sum lookup table, returning the sum of the area enclosed by 
 * the rectangle (x1,y1,x2,y2) where (x1,y1) is the top-left corner and (x2,y2) is the
 * bottom-right corner.
 *
*/
unsigned long int query_sum(unsigned long int *A, int n, int x1, int y1, int x2, int y2){
	unsigned long int r1 = *(A + y2 * n + x2);
	unsigned long int r2 = x1 > 0 ? *(A + y2 * n + x1 - 1) : 0;
	unsigned long int r3 = y1 > 0 ? *(A + (y1 - 1) * n + x2) : 0;
	unsigned long int r4 = x1 > 0 && y1 > 0 ? * (A + (y1 - 1) * n + x1 - 1) : 0;
	return r1 - r2 - r3 + r4;
}
