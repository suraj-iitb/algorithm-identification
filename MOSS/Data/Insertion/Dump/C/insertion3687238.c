#include <stdio.h>

int main(){

  int Num;
  scanf("%d",&Num);
  int A[Num];

  for(int a = 0; a < Num; a++){
  scanf("%d",&A[a]);
  }

  for(int c = 0; c < Num ; c++){
    if(c < Num-1)
    {
        printf("%d ",A[c]);
        continue;
    }
    else
    printf("%d",A[c]);
  }
  printf("\n");

int j;
for(int i = 1; i < Num; i++){
  
  int key = A[i];
  j = i - 1;
  while(j >= 0 && A[j] > key){
    A[j+1] = A[j];
    j--;
    A[j+1] = key;
  }
  for(int c = 0; c < Num ; c++){
    if(c < Num-1)
    {
        printf("%d ",A[c]);
        continue;
    }
    else
    printf("%d",A[c]);
  }
  printf("\n");
}

return (0);
}

