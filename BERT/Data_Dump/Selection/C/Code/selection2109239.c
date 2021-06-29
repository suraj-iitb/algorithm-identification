#include<stdio.h>
#include<stdlib.h>
#define mymalloc(p,n) {p = malloc((n)*sizeof(*p));if ((p)==NULL) {printf("not enough memory?\n"); exit(1);};}


int *readArray(int *num){
	int i,j;
	int *A;
	scanf("%d", num);
	mymalloc(A,*num);
	for(i=0;i<*num;i++){
		scanf("%d",&j);
		A[i]=j;
	}
	return A;
}

void swapIJ(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void printArray(int *A, int num){
	int k;
	for(k=0;k<num;k++){
		printf("%d",A[k]);
		if(k<num-1){
			printf(" ");
		}
		else{printf("\n");}
	}
}

main(){
	int i,j,num,mini,count;
	int *A;
	A=readArray(&num);
	count=0;
	for(i=0;i<num;i++){
		mini=i;
		for(j=i+1;j<num;j++){
			if(A[j]<A[mini]){mini=j;}
		}
		if(i!=mini){
			count++;
			swapIJ(&A[i],&A[mini]);
		}
	}
	printArray(A,num);
	printf("%d\n",count);
	return 0;
}
