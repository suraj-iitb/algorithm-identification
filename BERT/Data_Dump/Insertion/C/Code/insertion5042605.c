#include<stdio.h>

void kota(int A[],int N){
  int haku;
  for(haku=0;haku<N;haku++){
    if(haku>0){
      printf(" ");
    }

    printf("%d",A[haku]);
  }
  printf("\n");
}

void sounyu(int A[],int N){
  int a,y,u;
  for(a=1;a<N;a++){
    y=A[a];
    u=a-1;
    while(u>=0&&A[u]>y){
      A[u+1]=A[u];
      u--;
    }
    A[u+1]=y;
    kota(A,N);
  }
}

int main(){
  int N,o,k;
   int A[100];
   scanf("%d",&N);
   for(o=0;o<N;o++){
     scanf("%d",&A[o]);
   }
   kota(A,N);
   sounyu(A,N);

   return 0;
}

