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

#include <stdio.h>
#include <stdlib.h>
#include "partialsums.h"

#define W 10
#define H 30
#define V 5

#define X1 0
#define Y1 0
#define X2 4
#define Y2 4

int main(){
	unsigned int A[W*H];

	for (int i = 0; i < W * H; i++)
		A[i] = V;

	unsigned long int *res = generate_lookup(A, H, W);

	printf("Original Matrix\n");
	for (int j = 0; j < H; j++){
		for (int i = 0; i < W; i++)
			printf("%5d", A[j*W + i]);
		printf("\n");
	}

	printf("\n");

	printf("Sum Lookup Matrix\n");
	for (int j = 0; j < H; j++){
		for (int i = 0; i < W; i++)
			printf("%5ld", res[j*W + i]);
		printf("\n");
	}
	printf("\n");

	printf("Sum of region with size %d x %d: %ld\n", X2 - X1 + 1, Y2 - Y1 + 1, query_sum(res, W, X1, Y1, X2, Y2));

	free(res);
	return 0;
}
