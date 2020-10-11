#include<stdio.h>
int main(){
  int n,arr[100],i,j,temp,min,count=0;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  for(i=0;i<n-1;i++){
    min=i+1;
    for(j=i+1;j<n;j++){
      if(arr[j]<arr[min]){
	min=j;
      }
    }
    if(arr[min]<arr[i]){
      temp=arr[i];
      arr[i]=arr[min];
      arr[min]=temp;
      count++;
    }
  }
  for(i=0;i<n;i++){    
    printf("%d",arr[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
