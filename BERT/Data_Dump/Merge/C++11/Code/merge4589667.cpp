/*
 * WelcomeToAtCoder.cpp
 *
 *  Created on: 2020/02/19
 *      Author: black
 */

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#define MAX 500000
#define INFTY 2000000000


int L[MAX/2+2];
int R[MAX/2+2];
int iCount;

void merge(int A[], int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	for(int i=0; i< n1; ++i){
		L[i] = A[left+i];
	}
	for(int i=0; i< n2; ++i){
		R[i] = A[mid+i];
	}
	L[n1] = INFTY;
	R[n2] = INFTY;

	int i= 0;
	int j= 0;

	for(int k=left; k<right; ++k){
		if (L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
		iCount++;
	}
}

void mergeSort(int A[], int left, int right){
	if ((left+1) < right){
		int mid = (left+right)/2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main(){
	int A[MAX];
	int n;
	iCount = 0;

	scanf("%d", &n);
	for(int i= 0; i< n; ++i){
		scanf("%d", &A[i]);
	}

	mergeSort(A, 0, n);

	for(int i= 0; i< n; ++i){
	    if(i){
	        cout << " ";
	    }
		cout << A[i];
	}
	cout << endl;
	cout << iCount << endl;


	return 0;

}

