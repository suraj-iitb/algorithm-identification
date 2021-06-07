#include <stdio.h>
#define N 100000
#define Q 500
int Search(int);
int S[N];
int n;
int main(){
  int i,j,q,count=0;
  int T[Q];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }
    for(j=0;j<q;j++){
      if(Search(T[j])==1)
	count++;
    }
  printf("%d\n",count);
  return 0;
}

int Search(int key){
  int i=0;
  S[n]=key;
  while(S[i]!=key)
    i++;
  if(i==n) return 0;
  else return 1;
}
