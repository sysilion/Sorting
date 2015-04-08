/*
 * sorting.h
 *
 *  Created on: 2015. 4. 2.
 *      Author: Administrator
 */

#ifndef SORTING_H_
#define SORTING_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define CHECK_TIME_START __int64 freq, start, end; if (QueryPerformanceFrequency((LARGE_INTEGER*)&freq)) {QueryPerformanceCounter((LARGE_INTEGER*)&start);
#define CHECK_TIME_END(a,b) QueryPerformanceCounter((LARGE_INTEGER*)&end); a=(float)((double)(end - start)/freq*1000*1000); b=TRUE; } else b=FALSE;

#define LOOP_COUNT 10 //
#define DATA_SIZE 10000

void swap(int *a, int *b);

void bubble();
void Bubble_Sort(int array[]);

void selectt();
void Select_Sort(int array[]);

void insert();
void Insert_Sort(int array[]);

void merge();
void Merge_Sort(int array[], int start, int end);
void Merge(int array[], int start, int mid, int end, int dummy[]);
void CopyArray(int B[], int A[], int n);

void quick();
void Quick_Sort(int array[]);



#endif /* SORTING_H_ */
