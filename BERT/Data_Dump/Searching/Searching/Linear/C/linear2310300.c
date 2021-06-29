#include <stdio.h>
#define MAX 10000
int n;
int S[MAX];
int linearsearch(int);
int main(){
  int q;
  int T[500];
  int i,j;
  int count=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    if(linearSearch(T[i])==1)
      count++;
  }
  printf("%d\n",count);

  return 0;
}

int linearSearch(int key){
  int i=0;
  S[n]=key;
  while(S[i]!=key){
    i++;
    if(i==n){
      return 0;
    }
  }
    return 1;
}
