/*
 * merge.c
 *
 *  Created on: 2015. 4. 2.
 *      Author: Administrator
 */

#include "sorting.h"

typedef struct MS {
	int array[DATA_SIZE];
} MS;

void merge() {
	extern int *input;
	int *copy_input[LOOP_COUNT];
	int i, j;

	// Time check variable
	double time;
	BOOL err;

	for (i = 0; i < LOOP_COUNT; i++) {
		copy_input[i] = (int *) malloc(sizeof(int) * DATA_SIZE);
		for (j = 0; j < DATA_SIZE; j++) { // copy data
			copy_input[i][j] = input[j];
		}
	}

	CHECK_TIME_START
	;
	for (i = 0; i < LOOP_COUNT; i++) {
		Merge_Sort(copy_input[i]);

		//		if(x%(LOOP_COUNT/10) == 0) printf("*");
		//		printf("Selecting Result --> input[%d] : %d\n", result, input[result]);
	}
	CHECK_TIME_END(time, err)
	;

	//	// data output check
	//	for (i = 0; i < DATA_SIZE; i++) {
	//		if(i%(DATA_SIZE/10) == 0) printf("%d : %d, ", i, copy_input[i]);
	//	}

	//	printf(" Calc Time = %.0fus\n", time/LOOP_COUNT);
	printf("%.0f\n", time / LOOP_COUNT);
}

void Merge_Sort(int array[], int start, int end) {
	int dummy[DATA_SIZE] = { };
	if (start < end) {
		int mid = floor((end - start) / 2);
		Merge_Sort(array, start, mid);
		Merge_Sort(array, mid + 1, end);
		Merge(array, start, mid, end, dummy);
	}
}

void Merge(int array[], int start, int mid, int end, int dummy[]) {
	int next = start;
	int lower1 = start;
	int lower2 = mid + 1;

	while (lower1 <= mid && lower2 <= end) {
		if (array[lower1] < array[lower2]) {
			dummy[next] = array[lower1];
			lower1++;
		} else {
			dummy[next] = array[lower2];
			lower2++;
		}
		next++;
	}

	if (lower1 <= mid) {
//		for(i = 0; i <=)
	}

}

void CopyArray( B[], A[], n) {
	int i;
	for (i = 0; i < n; i++)
		A[i] = B[i];
}
