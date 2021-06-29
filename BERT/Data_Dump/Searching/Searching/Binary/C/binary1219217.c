/*
 * Binary Search.c
 *
 *  Created on: 2015/02/15
 */

#include <stdio.h>

int S[100000]={0},T[50000]={0};


//void printarray(int a[],int n){
//	int i;
//	for(i=0;i<n;i++){
//		printf("%d ",a[i]);
//	}printf("\n");
//}

int main(){
	int n,q;
	int i,j,counter=0;
	int start,end;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}

	scanf("%d",&q);
	for(j=0;j<q;j++){
		scanf("%d",&T[j]);
	}


	for(i=0;i<q;i++){

		start=0,end=n;

		while(start < end){
			int middle = (start + end) / 2;

			if(S[middle] > T[i]){
				end = middle;
			}
			else if(S[middle] < T[i]){
				start = middle + 1;
			}
			else if(S[middle] == T[i]){
				counter++;
				break;
			}
		}
	}

	printf("%d\n",counter);

	return 0;
}
