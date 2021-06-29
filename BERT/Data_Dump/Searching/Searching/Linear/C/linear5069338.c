#include<stdio.h>
#define N 10000
#define Q 500

int linearSearch(int);

int S[N];
int T[Q];
int n;

int main(){
  
  int i,q,count=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    count = count + linearSearch(T[i]);
  }

  printf("%d\n",count);

  return 0;
}

int linearSearch(int x){

  int i=0;
  
  while(S[i] != x){
    i++;
    if(i == n)return 0;
  }
  return 1;
  
}

