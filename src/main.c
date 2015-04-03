/*
 * main.c
 *
 *  Created on: 2015. 4. 2.
 *      Author: Administrator
 */

#include "sorting.h"

int *input;

int main() {
	int go, size, i, file;
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


	switch(file) {
	case 1:
		fp = fopen("random10000.txt","r");
		break;
	case 2:
		fp = fopen("random10000.txt","r");
		break;
	case 3:
		fp = fopen("random10000.txt","r");
		break;
	case 4:
		fp = fopen("random10000.txt","r");
		break;
	case 5:
		fp = fopen("random10000.txt","r");
		break;
	}

	input = (int *) malloc(sizeof(int) * DATA_SIZE);

	for (i = 0; i < DATA_SIZE; i++) { // fill data
		fscanf(fp, "%d, ", &input[i]);
	}

	switch (go) {
	case 1:
		bubble();
		break;
	case 2:
		selectt();
		break;
	case 3:
		insert();
		break;
	case 4:
//		merge();
		break;
	case 5:
//		quick();
		break;
	case 6:
		bubble();
		selectt();
		insert();
//		merge();
//		quick();
		break;
	}

	return 0;
}

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
