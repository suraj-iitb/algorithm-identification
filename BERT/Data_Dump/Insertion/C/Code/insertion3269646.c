#include <stdio.h>
#include <stdlib.h>

void insertSort(int*,int);
int main(){

int i,N,*array;
scanf("%d",&N);
array=(int *)malloc(N*sizeof(int));
for(i=0;i<N;i++){
scanf("%d",&array[i]);
}
insertSort(array,N);
return 0;
}

void insertSort(int* array,int N){
    int i,v,j,l;
    for(l=0;l<N-1;l++) printf("%d ",array[l]);
    printf("%d",array[N-1]);
    printf("\n");
     for(i=1;i<=N-1;i++){
        v=array[i];
        j=i-1;
        while(j>=0 && array[j]>v){
            array[j+1]=array[j];
            j--;
            array[j+1]=v;
        }
        for(l=0;l<N-1;l++){
        printf("%d ",array[l]);
        }
	printf("%d",array[N-1]);
        printf("\n");
    }
            
 }

