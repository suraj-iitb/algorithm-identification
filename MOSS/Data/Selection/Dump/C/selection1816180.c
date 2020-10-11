/*
 ============================================================================
 Name        : selectionsort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int selectionSort(int a[100],int n){
	int kaisuu=0;
	int j,i;
	int minj;
	int tmp;
	for(i=0;i<n;i++){
		minj=i;
		for(j=i;j<n;j++){
			if(a[j]<a[minj]){
				minj=j;
			}
		}
		tmp=a[i];
		a[i]=a[minj];
		a[minj]=tmp;
		if(i!=minj){kaisuu++;
		}}
	return kaisuu;
}

int main(void) {

	int n;
	int koukankaisuu=0;
	int a[100];
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	koukankaisuu=selectionSort(a,n);

	printf("%d",a[0]);
	for(i=1;i<n;i++){
		printf(" %d",a[i]);
	}
	printf("\n%d\n",koukankaisuu);

	return 0;
}
