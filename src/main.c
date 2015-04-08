/*
 * main.c
 *
 *  Created on: 2015. 4. 2.
 *      Author: Administrator
 */

#include "sorting.h"

void IS(int array[]);

int *input = NULL;

int main() {
	int go, i, file;
	int *input_dummy;
	FILE *fp;

	printf("\n\t\tSelect Menu");
	printf("\n\t1. Bubble Sort");
	printf("\n\t2. Select Sort");
	printf("\n\t3. Insert Sort");
	printf("\n\t4. Merge Sort");
	printf("\n\t5. Quick Sort");
	printf("\n\t6. ALL Sort");
	printf("\n\t");
	printf("\n\t0. Exit");
	printf("\n\t");

	scanf("%d", &go);

	printf("select data : ");
	scanf("%d", &file);

	switch (file) {
	case 1:
		fp = fopen("1.unrank_uns_uns.txt", "r");
		break;
	case 2:
		fp = fopen("2.rank_uns_uns.txt", "r");
		break;
	case 3:
		fp = fopen("1.unrank_uns_uns.txt", "r");
		input_dummy = (int *) malloc(sizeof(int) * DATA_SIZE / 2);
		for (i = 0; i < DATA_SIZE / 2; i++) {
			fscanf(fp, "%d, ", &input_dummy[i]);
		}
		IS(input_dummy); // half sorting
		input = (int *) malloc(sizeof(int) * DATA_SIZE);
		for (i = 0; i < DATA_SIZE; i++) { // fill data
			if (i < DATA_SIZE/2) {
				input[i] = input_dummy[i];
//				if(i%(DATA_SIZE/100) == 0) printf("%d ", input[i]);  // sorting check
			} else {
				fscanf(fp, "%d, ", &input[i]);
			}
		}
		break;
	case 4:
		fp = fopen("4.rank_sort_uns.txt", "r");
		break;
	case 5:
		fp = fopen("4.rank_sort_uns.txt", "r");
		input_dummy = (int *) malloc(sizeof(int) * DATA_SIZE / 2);
		for (i = 0; i < DATA_SIZE / 2; i++) {
			fscanf(fp, "%d, ", &input_dummy[i]);
		}
		input = (int *) malloc(sizeof(int) * DATA_SIZE);
		for (i = 0; i < DATA_SIZE / 2; i++) {
			input[i] = input_dummy[i] * 2;
			input[i + DATA_SIZE/2] = input_dummy[i] * 2 -1;
//			if(i%(DATA_SIZE/10/2) == 0) printf("%d ", input[i]); // sorting check
//			if((i+DATA_SIZE/2)%(DATA_SIZE/10/2) == 0) printf("%d ", input[i+DATA_SIZE/2]); // sorting check
		}
		break;
	}

	if (input == NULL) {
		input = (int *) malloc(sizeof(int) * DATA_SIZE);
		for (i = 0; i < DATA_SIZE; i++) { // fill data
			fscanf(fp, "%d, ", &input[i]);
		}
	}
	free(input_dummy);
	fclose(fp);

	switch (go) {
	case 1:
		bubble();
		break;
	case 2:
		insert();
		break;
	case 3:
		selectt();
		break;
	case 4:
		merge();
		break;
	case 5:
		quick();
		break;
	case 6:
		bubble();
		insert();
		selectt();
		merge();
		quick();
		break;
	}

	free(input);
	return 0;
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void IS(int array[]) {
	int i, j;
	for (i = 0; i < DATA_SIZE/2; i++){
	    for (j = i; j > 0 && array[j-1] > array[j]; j--){
	        swap(&array[j], &array[j-1]);
	    }
	}
}
