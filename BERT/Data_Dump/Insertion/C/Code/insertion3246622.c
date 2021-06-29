/*
 * 1_2.c
 *
 *  Created on: 2018/11/20
 *      Author: masato
 */

#include <stdio.h>

int main(void){
	int n,i,j,x,v,m;
	scanf("%d", &n);
	int value[n];

	for(i=0;i<n;i++){
		scanf("%d", &x);
		value[i] = x;

		printf("%d", x);
		if(i==n-1){
			printf("\n");
		} else{
			printf(" ");
		}
	}

	for(i=1;i<n;i++){
		v = value[i];
		j = i-1;
		while(j >=0 && value[j] > v){
			value[j+1] = value[j];
			j--;
		}
		value[j+1] = v;
		for(m=0;m<n;m++){
			printf("%d", value[m]);
			if(m==n-1){
				printf("\n");
			} else{
				printf(" ");
			}
		}
	}
}

