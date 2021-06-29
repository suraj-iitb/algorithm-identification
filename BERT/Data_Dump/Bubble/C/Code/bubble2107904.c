#include<stdio.h>
#include<stdlib.h>
#define mymalloc(p,n) {p = malloc((n)*sizeof(*p));if ((p)==NULL) {printf("not enough memory?\n"); exit(1);};}
main(){
	int i,j,k,num,temp,count;
	int *A;
	scanf("%d", &num);
	mymalloc(A,num);
	for(i=0;i<num;i++){
		scanf("%d",&j);
		A[i]=j;
	}
	count=0;
	for(i=0;i<num;i++){
		for(j=num-1;j>i;j--){
			if(A[j]<A[j-1]){
				temp=A[j];
				A[j]=A[j-1];
				A[j-1]=temp;
				count++;
			}
		}
		
	}
	for(k=0;k<num;k++){
		printf("%d",A[k]);
		if(k<num-1){
			printf(" ");
		}
		else{printf("\n");}
	}
	printf("%d\n",count);
	return 0;
}
