/*
 * quick.c
 *
 *  Created on: 2015. 4. 2.
 *      Author: Administrator
 */

#include "sorting.h"

void quick() {
	extern int *input;
	int *copy_input[LOOP_COUNT];
	int i, j;

	// Time check variable
	double time;
	BOOL err;

	for (i = 0; i < LOOP_COUNT; i++){
		copy_input[i] = (int *) malloc(sizeof(int) * DATA_SIZE);
		for (j = 0; j < DATA_SIZE; j++) { // copy data
			copy_input[i][j] = input[j];
		}
	}

	CHECK_TIME_START;
	for (i = 0; i < LOOP_COUNT; i++) {
		Quick_Sort(copy_input[i], DATA_SIZE);

		//		if(x%(LOOP_COUNT/10) == 0) printf("*");
		//		printf("Selecting Result --> input[%d] : %d\n", result, input[result]);
	}
	CHECK_TIME_END(time, err);

	//	// data output check
	//	for (i = 0; i < DATA_SIZE; i++) {
	//		if(i%(DATA_SIZE/10) == 0) printf("%d : %d, ", i, copy_input[i]);
	//	}

	//	printf(" Calc Time = %.0fus\n", time/LOOP_COUNT);
	printf("%.0f\n", time / LOOP_COUNT);
}

void Quick_Sort (int array[], int size) {
    int i, j, p, t;
    if (size < 2)
        return;
    p = array[size / 2];
    for (i = 0, j = size - 1;; i++, j--) {
        while (array[i] < p)
            i++;
        while (p < array[j])
            j--;
        if (i >= j)
            break;
        t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
    Quick_Sort(array, i);
    Quick_Sort(array + i, size - i);
}

