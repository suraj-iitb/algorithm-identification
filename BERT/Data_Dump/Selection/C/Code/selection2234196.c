#include <stdio.h>
#define MAX 100

int main(void){
 int A[MAX]={0},N,S=0;
 int a,b,c,min,tmp;

 scanf("%d",&N);

 for(a=0;a<N;a++){
  scanf("%d",&A[a]);
 }

 for(b=0;b<N;b++){
  min=b;
  for(c=b;c<N;c++){
   if(A[c]<A[min]){min=c;}
  }
  if(A[b]!=A[min]){
      S++;
      tmp=A[b];
      A[b]=A[min];
      A[min]=tmp;
  }
 }

 for(a=0;a<N;a++){
  printf("%d",A[a]);
  if(a!=N-1){printf(" ");}
 }
 
 printf("\n%d\n",S);
 
 return 0;
}
