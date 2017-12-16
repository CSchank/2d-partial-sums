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

unsigned long int *generate_lookup(unsigned int *A, int m, int n);
unsigned long int query_sum(unsigned long int *A, int n, int x1, int y1, int x2, int y2);
