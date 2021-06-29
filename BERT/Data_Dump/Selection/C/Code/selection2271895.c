#include <stdio.h>

int main(){
  int N,i,j,minj,cnt=0,a[100],t;
  
  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  
  for(i = 0;i < N;i++){
    
    minj=i;
    
    for(j = i;j < N;j++){
      
      if(a[j] < a[minj]){
	minj = j;}
    }  
      t = a[minj];
      a[minj] = a[i];
      a[i] = t;	
      if(i!=minj){
	cnt += 1;
      }
  }
  
    
  for(i=0;i<N;i++){
    printf("%d",a[i]);
    
    if(i==N-1){
      printf("\n");
    }
    
    else printf(" ");
  }
  
  printf("%d\n",cnt);
  
  return 0;
}
