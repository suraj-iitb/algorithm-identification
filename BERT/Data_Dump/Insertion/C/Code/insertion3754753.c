#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void dump(int N,int *p){
	int i;
	for(i=0;i<N;i++){
		printf("%d",p[i]);
		if(i==N-1)printf("\n");
		else printf(" ");
	}
	
}
int 
main(){
	int N,a[100];	
	scanf("%d",&N);
	int i;
	for(i=0;i<N;i++)scanf("%d",&a[i]);
	int j=0,k=0;
	int key=0,sumR=0;
	
	dump(N,a);
	for(i=1;i<=N-1;i++){
		key = a[i];
		j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1] = a[j];
			a[j]=key;
			j--;
			
			
		}
		a[j+1]=key;
		dump(N,a);
	}

 return 0;
}
