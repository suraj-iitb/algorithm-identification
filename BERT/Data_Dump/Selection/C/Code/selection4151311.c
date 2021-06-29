#include<stdio.h>
#define D 100

int sS(int A[],int N){
  int a,b,c,d=0,e;
  for(a=0;a<N-1;a++){
    e = a;
    for(b = a;b<N;b++) {
      if(A[b]<A[e]) e = b;
    }
    c = A[a];A[a] = A[e];A[e] = c;
    if(a!= e) d++;
  }
  return d;
}




int main(){
  int A[D],a,b,N;

  scanf("%d",&N);
  if(N<0||N>100) return 0;

  
  for(a = 0;a<N;a++)
    scanf("%d",&A[a]);

  b = sS(A,N);

  for(a = 0;a<N;a++){
    if(a>0) printf(" ");
    printf("%d",A[a]);
  }
  printf("\n");
  printf("%d\n",b);

  return 0;
}
