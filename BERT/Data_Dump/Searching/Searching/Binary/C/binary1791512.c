#include <stdio.h>

int search(int);
int S[100000];
int T[50000];
int n,q;

int main(){
  int i,count=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q); 
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    count=count+search(T[i]);
  }

  printf("%d\n",count);
  return 0;
}

int search(int a){

  int L=0,R,M;
  R=n;
  
  while(L<R){
    M=(L+R)/2;
    if(S[M]==a) return 1;
    else if(S[M]<a) L=M+1;
    else if(S[M]>a) R=M;
  }
  return 0;
}
