#include <stdio.h>

int main(){

  int i,n,flag = 1,arr[100],tmp,count = 0;;

  //in
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  
  //sort
  while(flag){
    flag = 0;
  
    for(i=n-1;i>0;i--){
      if(arr[i]<arr[i-1]){
	tmp = arr[i-1];
	arr[i-1] = arr[i];
	arr[i] = tmp;
	flag = 1;
	count++;
      }
    }
  }
  
  //out
  for(i=0;i<n;i++){
    if(i!=0) printf(" ");
    printf("%d",arr[i]);
  }
  printf("\n%d\n",count);
  
  
  return 0;

}
