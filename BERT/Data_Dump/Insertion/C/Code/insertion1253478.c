#include<stdio.h>

int main(){


	int i,j,key,k;
	int a;
	int A[100000];

	scanf("%d",&a);
	

	for(i=0;i<a;i++)scanf("%d",&A[i]);
	for(k=0;k<a;k++){printf("%d",A[k]);
	if(k!=a-1)printf(" ");
	
	}
	printf("\n");


	for(i = 1;i<a;i++){
    key = A[i];
    /* insert A[i] into the sorted sequence A[0,...,j-1] */
    j = i - 1;
	while (j >= 0 && A[j] > key){
        A[j+1] = A[j];
        j--;
    A[j+1] = key;

	}

	for(k=0;k<a;k++){printf("%d",A[k]);
	if(k!=a-1)printf(" ");
	
	}
	printf("\n");
}



	return 0;
}
