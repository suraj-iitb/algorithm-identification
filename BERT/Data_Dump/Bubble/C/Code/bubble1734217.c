#include<stdio.h>

#define N 100

int main(){
  
  int i,j,n,flag,tmp,count = 0;
  int arr[N];
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  
  for(i=0;i<n;i++){
    flag=1;
    while(flag){
      flag = 0;
      for(j=n-1;j>=1;j--){
	if(arr[j]<arr[j-1]){
	  tmp = arr[j];
	  arr[j] = arr[j-1];
	  arr[j-1] = tmp;
	  count++;	
	  flag=1;
	  break;
	}}}}

  for(j=0;j<n-1;j++){
    printf("%d ",arr[j]);
  }
  
  printf("%d\n",arr[n-1]);
  
  printf("%d\n",count);
  
  
  return 0;
}
