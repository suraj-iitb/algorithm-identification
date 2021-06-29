#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* mat,int n);

int main(void){
	int* mat;
	int i,n;

	scanf("%d",&n);
	mat=(int* )malloc(n*sizeof(int));

	for(i=0;i<n;i++) scanf("%d",&mat[i]);
	
	bubbleSort(mat,n);

	free(mat);
	return 0;
}

void bubbleSort(int* mat,int n){
   	int flag = 1;
   	int j;
   	int temp,count=0;
   	                    // ????????£??\????´?????????¨??????
   	while(flag){
     	flag = 0;
     	for(j=n-1;j>0;j--){
       		if(mat[j] < mat[j-1]){
	        	temp=mat[j];
	        	mat[j]=mat[j-1];
	        	mat[j-1]=temp;
   			 	flag = 1;
   			 	count++;
	   		}
     	}
    }
    printf("%d",mat[0]);
	for(j=1;j<n;j++)  printf(" %d",mat[j]);
	printf("\n");
   printf("%d\n",count);

}
