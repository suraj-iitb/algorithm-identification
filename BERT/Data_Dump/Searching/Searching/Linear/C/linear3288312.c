#include<stdio.h>

int linearSearch(int*,int*,int,int);

int main(){
  int n,q,i;
  int S[10000],T[500];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  printf("%d\n",linearSearch(S,T,n,q));
  return 0;
}

int linearSearch(int *S,int *T,int n,int q){
  int cnt=0,i,j;
  
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i] == S[j]){
	cnt++;
	break;
      }
    }
  }
  return cnt;
}

