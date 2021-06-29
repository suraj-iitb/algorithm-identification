#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAX 100000
#define SENTINEL 1000000001

struct Card {char suit; int value;};

struct Card L[MAX/2+2], R[MAX/2+2];

void merge(struct Card A[], int n, int left, int mid, int right){
	int n1 = mid - left;
	int n2 = right - mid;
	for(int i=0; i<n1; i++) L[i]=A[left+i];
	for(int i=0; i<n2; i++) R[i]=A[mid+i];
	L[n1].value = R[n2].value = SENTINEL;
	int i = 0, j = 0;

	for(int k=left; k<right; k++){
		if(L[i].value <= R[j].value){
			A[k] = L[i++];
		} else {
			A[k] = R[j++];
		}
	}
}

void mergeSort(struct Card A[], int n, int left, int right){
	int mid;
	if(left+1 < right){
		mid = (left + right)/2;
		mergeSort(A, n, left, mid);
		mergeSort(A, n, mid, right);
		merge(A, n, left, mid, right);
	}
}

int partition(struct Card A[], int n, int p, int r){
	struct Card x = A[r];
	int i = p-1;
	struct Card tmp;
	for(int j = p; j<r; j++){
		if(A[j].value <= x.value){
			i++;
			tmp = A[i]; A[i]=A[j]; A[j]=tmp;
		}
	}
   tmp = A[i+1]; A[i+1]=A[r]; A[r]=tmp;
   return i+1;
}

void quickSort(struct Card A[], int n, int p, int r){
	int q;
	if(p<r){
		q = partition(A, n, p, r);
		quickSort(A, n, p, q-1);
		quickSort(A, n, q+1, r);
	}
}

int main(){
	int n; cin >> n;
	struct Card A[MAX], B[MAX];

	int x;
	char S[2];
	for(int i=0; i<n; i++){
		cin >> S >> x;
		A[i].suit = B[i].suit = S[0];
		A[i].value = B[i].value = x;
	}

	mergeSort(A, n, 0, n);
	quickSort(B, n, 0, n-1);

	bool stable = 1;
	for(int i=0; i<n; i++){
		if(A[i].suit != B[i].suit) stable = 0;
	}

	if (stable) cout << "Stable" << endl;
	else cout << "Not stable" << endl;
	for(int i=0; i<n; i++) cout << B[i].suit << " " << B[i].value << endl;

	return 0;
}


