#include<stdio.h>
int main(){
  int suuretu[100],N,a,kaisuu;
  scanf("%d",&N);
  for(a=0;a<N;a++)scanf("%d",&suuretu[a]);

  kaisuu=selectionSort(suuretu,N);
  for(a=0;a<N;a++){
    if(a>0)printf(" ");
      printf("%d",suuretu[a]);
  }
  printf("\n");
  printf("%d\n",kaisuu);
  return 0;
}
int selectionSort(int suuretu[],int N){
  int a,b,c,kaisuu=0,minj;
  for(a=0;a<N-1;a++){
    minj=a;
    for(b=a;b<N;b++){
      if(suuretu[b]<suuretu[minj])minj=b;
    }
    c=suuretu[a];
    suuretu[a]=suuretu[minj];
    suuretu[minj]=c;
    if(a!=minj)kaisuu++;
  }
  return kaisuu;
  
}
