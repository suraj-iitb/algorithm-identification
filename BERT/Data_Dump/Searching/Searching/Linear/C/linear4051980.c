#include<stdio.h>

#define N 100000
int linearSearch(int *, int,int);

int main(){
  int i,j,a,b,n=0,m;
  int S[N],T[N];

  scanf("%d",&i);

  for(a=0;a<i;a++){
    scanf("%d",&S[a]);
  }

  scanf("%d",&j);

  for(b=0;b<j;b++){
    scanf("%d",&T[b]);
  }

  for(a=0;a<j;a++){
    m=linearSearch(S,T[a],i);
    if(m==-1) continue;
    else n++;
  }

  printf("%d\n",n);
  
  return 0;
}

int linearSearch(int *A,int key,int n){
  int i;
  
  for(i=0;i<n;i++){
    if(A[i]==key) return i;
  }

  return -1;
}

