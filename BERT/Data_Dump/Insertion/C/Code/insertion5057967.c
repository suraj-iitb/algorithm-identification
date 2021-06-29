#include <stdio.h>

int main(){
  int i,j,k,N,key;
  
  scanf("%d",&N);
  int data[N];
  for(i = 0 ; i < N ; i++) scanf("%d",&data[i]);
  for(i = 0 ; i < N ; i++){
    key = data[i];
    j = i - 1;
    while(j >= 0 && data[j] > key){
      data[j+1] = data[j];
      j--;
      data[j+1] = key;
    }
    for(k = 0 ; k < N - 1 ;k++) printf("%d ",data[k]);
    printf("%d\n",data[N-1]);
      
  }
  return 0;
}
    
    

