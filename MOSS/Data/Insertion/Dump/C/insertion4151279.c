#include<stdio.h>
#define N 1000

void out(int A[],int B) {
  int a;
  for(a=0;a<B;a++){
    if(a>0) printf(" ");
    printf("%d",A[a]);
  }
  printf("\n");
}
void sort(int A[],int B){
  int a,b,c;
  for(a=1;a<B;a++){
    b = A[a];
    c = a-1;
    while(c>=0&& A[c]>b){
      A[c+1]=A[c];
      c--;
    }
    A[c+1]=b;
    out(A,B);
  }
}



    
int main(){
  int A,a,b;
  int B[N];

  scanf("%d",&A);
  if(A==0||A>100)return 0;
  for(a=0;a<A;a++) scanf("%d",&B[a]);

  out(B,A);
  sort(B,A);

  return 0;
}

