#include<stdio.h>

int selectionSort(int b[], int N){
  int i,j,t,sw=0,minj;
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(b[j]<b[minj]) minj=j;
    }
    t=b[i];
    b[i]=b[minj];
    b[minj]=t;
    if(i!=minj) sw++;
  }
  return sw;
}

int main(){
  int b[100],N,i,sw;
  
  
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&b[i]);
  
  sw=selectionSort(b,N);
  
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",b[i]);
  }
  printf("\n");
  printf("%d\n",sw);
  
  return 0;
}

