#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *,int);
int main(){
    int i,n;
    int *array;
    
    scanf("%d",&n);
    array=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
       scanf("%d",&array[i]);
    }
    bubbleSort(array,n);
return 0;
}

void bubbleSort(int *array,int n){
    int i,j,temp;
    int flag;
    int count=0;
    
    while(1){
        flag=0;
       for(i=n-1;i>0;i--){
        if(array[i]<array[i-1]){
          temp=array[i];
          array[i]=array[i-1];
          array[i-1]=temp;
          
          count++;
          flag=1;
        }
       }
       if(flag==0) break;
    }
    for(j=0;j<n-1;j++){
        printf("%d ",array[j]);
    }
    printf("%d",array[n-1]);
    printf("\n");
    printf("%d\n",count);
}

