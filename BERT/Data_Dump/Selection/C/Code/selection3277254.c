#include <stdio.h>
#include <stdlib.h>
void selectionSortAndShow(int*,int);
int main(){
    int i,N,*array;
scanf("%d",&N);
array=(int *)malloc(N*sizeof(int));
for(i=0;i<N;i++){
scanf("%d",&array[i]);
}
selectionSortAndShow(array,N);
return 0;
}

void selectionSortAndShow(int *array,int N){
    int i,j,min,s,temp,count=0;

    for(i=0;i<N-1;i++){
        s=i;
        for(j=i+1;j<N;j++){
	  if(array[j]<array[s]){
               s=j;    
            }
        }
	if(array[i]!=array[s]){ 
          temp=array[i];
          array[i]=array[s];
          array[s]=temp;
          count++;
	}
      
    }
    for(i=0;i<N-1;i++){
        printf("%d ",array[i]);
    }
    printf("%d",array[N-1]);
    printf("\n");
     printf("%d\n",count);

}

