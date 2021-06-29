#include<stdio.h>

void output(int T[], int K);
void insert(int T[], int K);

int main(){
  int A,i,T[100],count=0;
  
  scanf("%d",&A);
 
  while(1){
    if(count==A)break;
    scanf("%d",&T[count]);
    count=count+1;
  }
  output(T, A);
  insert(T, A);

  return 0;
  
}
void output(int T[], int K){
  int i;
  for(i=0; i < K; i++){
    if(i > 0){
      printf(" ");
    }
    printf("%d",T[i]);
  }
  printf("\n");
}
void insert(int T[], int K){
  int i, j, a;
  for(i=1; i < K; i++){
    a=T[i];
    j=i-1;
    while(j>=0 && T[j] > a){
      T[j+1]=T[j];
      j--;
    }
    T[j+1]=a;
    output(T, K);
  }
}



