#include<stdio.h>
#define A 100

int count=0;

int swap (int *x,int *y){
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}

int bubble_sort(int data[],int size){
  int i,j;
  for(i=0;i<size-1;i++){
    for(j=size-1;j>=i+1;j--){
      if(data[j]<data[j-1]){
        swap(&data[j],&data[j-1]);
        count++;
      }
    }
  }
}

int main(){
  int data[A];
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }

  bubble_sort(data,n);

  for(i=0;i<n-1;i++){
        printf("%d ",data[i]);
  } 
  printf("%d\n",data[i]);
  printf("%d\n",count);
    return 0;
}
