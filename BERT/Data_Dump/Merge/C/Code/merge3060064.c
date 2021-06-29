/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File: main.c
* Author: Ivan
*
* Created on July 2, 2018, 3:17 PM
*/

#include <stdio.h>
#include <stdlib.h>
#define INFTY 1000000001
#define MAX_SIZE 500000
/*
*
*/

int Left[MAX_SIZE/2 + 2], Right[MAX_SIZE/2 + 2];
int count = 0;

void merge(int A[], int left, int mid, int right);
void mergeSort(int A[], int left, int right);

int main(int argc, char** argv) {
int *A, n;
scanf("%d", &n);
A = (int *)malloc(sizeof(int) * n);

for (int jx = 0; jx < n; ++jx) scanf("%d", &A[jx]);

mergeSort(A, 0, n);

for (int ix = 0; ix < n; ++ix)
{
if (ix) printf(" ");
printf("%d", A[ix]);
}
printf("\n%d\n", count);

return (EXIT_SUCCESS);
}

void merge(int A[], int left, int mid, int right)
{
int n1 = mid - left;
int n2 = right - mid;
for (int i = 0; i < n1; ++i) Left[i] = A[left + i];
for (int j = 0; j < n2; ++j) Right[j] = A[mid + j];
Left[n1] = INFTY;
Right[n2] = INFTY;
int i = 0, j = 0;
for (int k = left; k < right; ++k)
{
if (Left[i] <= Right[j])
{
A[k] = Left[i];
i = i + 1;
}
else
{
A[k] = Right[j];
j = j + 1;
}
count++;
}
}

void mergeSort(int A[], int left, int right)
{
if (left + 1 < right)
{
int mid = (left + right) / 2;
mergeSort(A, left, mid);
mergeSort(A, mid, right);
merge(A, left, mid, right);
}
}
