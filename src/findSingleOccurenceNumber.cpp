/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include <stdio.h>

int findSingleOccurenceNumber(int *A, int len) {

	if (A == NULL)
		return -1;

	int k = 0;
	int i;
	int temp[100];
	for (i = 0; i<len; i++)
	{
		int j;
		for (j = 0; j<i; j++)
		if (A[i] == A[j])
			break;

		if (i == j){
			temp[k] = A[i];			//unique Array
			k++;
		}
	}

	int j, count;
	int c[100];

	for (i = 0; i<k; i++){
		j = i;
		count = 0;
		while (j != len){
			if (temp[i] == A[j]){
				count++;
			}
			j++;
		}
		c[i] = count;						//count Array
	}

	int y;

	for (i = 0; i<k; i++){
		if (c[i] == 1){
			j = i;
			while (j<k){
				if (c[j + 1] == 1){
					y = -1;
					break;
				}
				else
					y = temp[i];
				j++;
			}
			break;
		}
		else
			y = -1;
	}
	return y;
}