#include<stdio.h>
#define N 100
int main(){
  int n,array[N],i,j,tmp,count=0,flag=0;
  scanf("%d",&n);

  for(i = 0;i < n; i++){
    scanf("%d",&array[i]);
  }

for(i = 0;i < n;i++){
  for(j = n-1;j > i;j--){
    if(array[j] < array[j-1]){
      tmp = array[j];
      array[j] = array[j-1]; 
      array[j-1] = tmp;
      count++;    
}
  }
}

  for(i = 0;i < n-1;i++){
    printf("%d ",array[i]);
}  
  printf("%d\n",array[n-1]);
 printf("%d\n",count);
  return 0;
}
