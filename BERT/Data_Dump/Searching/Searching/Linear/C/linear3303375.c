#include<stdio.h>

int search1(int S[],int n,int T);
int search2(int S[],int n,int T);

int main(void)
{
  int n,q,S[10000],T;
  int i,j;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }

  j = 0;
  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&T);
    
    if(search1(S,n,T) != search2(S,n,T)){
      j++;
    }
    
  }
  printf("%d\n",j);

  return 0;
}


int search1(int S[],int n,int T){
  int i = 0;
  
  S[n] = T;
  while(S[i] != T){
    i++;
  }
  return i;
}

int search2(int S[],int n,int T){
  int i = 0;
  
  S[n] = T;
  while(S[i] != T){
    i++;
  }
  return n;
}

