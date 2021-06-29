#include<stdio.h>

#define N 100000
#define Q 50000

int S[N];
int T[Q];

int search(int *,int,int);

int main(){
  int i;
  int n,q;
  int C=0;

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
  int i;
  int middle,left=0,right=n;

  while(left<right){
    middle=(left+right)/2;
    if(S[middle]==t) return 1;
    else if(t<S[middle]) right=middle;
    else if(t>S[middle]) left=middle+1;
  }
  return 0;
}

