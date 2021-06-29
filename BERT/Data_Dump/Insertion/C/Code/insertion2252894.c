#include<stdio.h>
#define N 100

int main(){
  int a,b[N],i,j,k,key=0;
  scanf("%d",&a);

  for(i = 0; i < a; i++)
    scanf("%d",&b[i]);
  
  for(i = 1; i < a; i++){
    for(k = 0; k < a-1; k++)
      printf("%d ",b[k]);

    printf("%d\n",b[a-1]);
    
    key = b[i];
    j = i-1;

    while(j >= 0 && b[j] > key){
      b[j+1] = b[j];
      j--;
    }
    
    b[j+1] = key;
    
  }

  for(k = 0; k < a-1; k++)
    printf("%d ",b[k]);
  
  printf("%d\n",b[a-1]);
  
  return 0;
}
