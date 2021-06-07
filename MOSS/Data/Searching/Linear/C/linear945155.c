#include<stdio.h>

#define N1 10000
#define N2 500

int main(){
  int S[N1+1];
  int T[N2+1];
  int n,q,i,j,key;
  int count=0;
  
  scanf("%d", &n);
  for( i = 0; i < n; i++ ) scanf("%d", &S[i]);
  scanf("%d", &q);
  for( i = 0; i < q; i++ ) scanf("%d", &T[i]);

  for(i=0;i<q;i++){
    key=T[i];
    j=0;
    S[n]=key;
    while(S[j]!=key){
      j++;
      
    }
    if(j!=n){
      count++;
    }
  }

  printf("%d\n",count);
  return 0;
}
