#include<stdio.h>
int main(){
  
  int arr[100],N,i,j,temp=0,count=0,minj;
  
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&arr[i]);

  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(arr[j]<arr[minj]){
	minj=j;  
      }
	
    }
    if(arr[i]!=arr[minj]){  temp=arr[i];
    arr[i]=arr[minj];
    arr[minj]=temp;
    count++;
    }
  }
  for(i=0;i<N;i++){
    printf("%d",arr[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n%d\n",count);
  
  return 0;
}
