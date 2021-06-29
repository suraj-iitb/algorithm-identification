#include<stdio.h>

#define N 10000
#define Q 500

int S[N];
int T[Q];

int search(int *,int,int);

int main(){
  int C=0;
  int n,q;
  int i;

  /*Input*/
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    if(search(S,n,T[i])==1) C++;
  }

  printf("%d\n",C);

  return 0;
}

int search(int *S,int n,int t){
  int i=0;

  S[n]=t;
  while(S[i]!=t){
    i++;
  }
  if(i!=n) return 1;
  return 0;
}

