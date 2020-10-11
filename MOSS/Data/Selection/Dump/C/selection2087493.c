#include <stdio.h>
#include <stdlib.h>

void selectionSort(int* mat,int n);

int main(void){
	int* mat;
	int i,n;

	scanf("%d",&n);
	mat=(int* )malloc(n*sizeof(int));

	for(i=0;i<n;i++) scanf("%d",&mat[i]);
	
	selectionSort(mat,n);

	free(mat);
	return 0;
}

void selectionSort(int* mat,int n){
   	int i,j,minj;
   	int temp,count=0;

   	for(i=0;i<n-1;i++){
   		minj=i;
   		for(j=i;j<n;j++){
   			if(mat[j]<mat[minj])	minj=j;
   		}
   		
   		if(mat[i]==mat[minj]) continue;
   		temp=mat[i];
   		mat[i]=mat[minj];
   		mat[minj]=temp;
   		count++;
   	}


    printf("%d",mat[0]);
	for(i=1;i<n;i++)  printf(" %d",mat[i]);
	printf("\n");
    printf("%d\n",count);

}
