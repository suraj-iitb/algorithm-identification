#include<stdio.h>
int main(){
  
  int arr[100],N,i,j,temp=0,count=0;
  
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&arr[i]);
  
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(arr[j]<arr[j-1]) {
	temp=arr[j];
	arr[j]=arr[j-1];
	arr[j-1]=temp;
	count++;
      }
    }
  }
  for(i=0;i<N;i++){
    printf("%d",arr[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}
