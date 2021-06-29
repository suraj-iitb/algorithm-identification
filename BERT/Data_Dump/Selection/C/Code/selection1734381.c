#include<stdio.h>

#define N 100

int main(){

  int i,j,n,minj,tmp,count=0;
  int arr[N];

  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }

  for(i=0;i<=n-1;i++){
    minj = i;
    for(j=i;j<=n-1;j++){
      if(arr[j]<arr[minj]){
	minj = j;
      }}
    if(arr[i]!=arr[minj]){	  
      tmp = arr[i];
      arr[i] = arr[minj];
      arr[minj] = tmp;
      count++;
    }}
  
  for(i=0;i<n-1;i++){
    printf("%d ",arr[i]);
  }

  printf("%d\n",arr[n-1]);

  printf("%d\n",count);

  return 0;
}
