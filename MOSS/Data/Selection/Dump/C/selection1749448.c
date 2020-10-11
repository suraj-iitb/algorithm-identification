#include <stdio.h>
int main(){
  
  int i,j,N[100],loop,count=0,num,min;
  
  scanf("%d",&loop);
  
  for(i=0; i<loop; i++){
    scanf("%d",&N[i]);
  }
  
  for(i=0; i<loop-1; i++){
    
    min = i;
    
    for(j=i; j<loop; j++){
      
      if(N[j] < N[min]){
	min = j;
      }
    }
    if(min == i) count--;
    num = N[i];
    N[i] = N[min];
    N[min] = num;
    count++;
  }
  
  for(i=0; i<loop-1; i++){
    printf("%d ",N[i]);
  }
  printf("%d\n",N[i]);
  printf("%d\n",count);
  
  return 0;
}
