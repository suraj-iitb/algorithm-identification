/*
 ============================================================================
 Name        : baburu.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int bubblrSort(int a[100],int n){
	int kaisuu=0;
	int j;
	int flag=1;
	while(flag){
		flag = 0;
		for(j=n-1;j>0;j--){
			if(a[j]<a[j-1]){
				int tmp;
				tmp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;
						flag = 1;
						kaisuu++;
			}
		}

	}

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
	koukankaisuu=bubblrSort(a,n);

	printf("%d",a[0]);
	for(i=1;i<n;i++){
			printf(" %d",a[i]);
		}
	printf("\n%d\n",koukankaisuu);

	return 0;
}
