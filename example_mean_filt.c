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
#include "partialsums.h"
#include <stdlib.h>

#define H 8
#define W 8
#define S 3

unsigned int picture[64] = 
	{
 	 255,255,255,255,255,255,255,255
	,255,255,255,255,255,255,255,255
	,255, 0 ,255,255,255,255, 0 ,255
	,255,255,255,255,255,255,255,255
	,255,255,255,255,255,255,255,255
	,255, 0 ,255,255,255,255, 0 ,255
	,255,255, 0 , 0 , 0 , 0 ,255,255
	,255,255,255,255,255,255,255,255
	};	

int main(){
	unsigned long int *sum_lookup = generate_lookup(picture, 8, 8);
	unsigned int *new_picture = malloc(H * W * sizeof(int));

	printf("Original picture\n");
	for (int j = 0; j < H; j++){
		for (int i = 0; i < W; i++)
			printf("%5d", picture[j*W + i]);
		printf("\n");
	}

	for (int j = 0; j < H; j++){
		for (int i = 0; i < W; i++){
			/* Handle edge cases */
			int x1 = i - S / 2 > 0 ? i - S / 2 : 0;
			int y1 = j - S / 2 > 0 ? j - S / 2 : 0;
			int x2 = i + S / 2 < W ? i + S / 2 : W - 1;
			int y2 = j + S / 2 < H ? j + S / 2 : H - 1;

			*(new_picture + j * W + i) = query_sum(sum_lookup, W, x1, y1, x2, y2) / ((x2 - x1 + 1) * (y2 - y1 + 1));
		}
	}

	printf("New picture\n");
	for (int j = 0; j < H; j++){
		for (int i = 0; i < W; i++)
			printf("%5d", new_picture[j*W + i]);
		printf("\n");
	}

	free(new_picture);
	free(sum_lookup);
	return 0;
}
