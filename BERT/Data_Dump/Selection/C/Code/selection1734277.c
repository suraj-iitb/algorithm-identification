#include <stdio.h>

int main(){

  int i,j,n,arr[100],minj,tmp,count = 0;;

  //in
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  
  //sort
  for(i=0;i<n-1;i++){
    minj = i;
    
    for(j=i;j<n;j++){
      if(arr[j]<arr[minj]) minj=j;
    }
    //swap
    if(i!=minj){
      tmp = arr[i];
      arr[i] = arr[minj];
      arr[minj] = tmp;
      count++;
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
