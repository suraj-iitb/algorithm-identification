#include<stdio.h>
#include<stdlib.h>

int ascending(const int *a, const int *b){
  return(*a - *b);
}

  int n,q;
  int S[100000];
  int T[50000];
  int C = 0;

  int solve(int mid,int key){
    if(T[mid] >= key){
      return 1;
    }else{
      return 0;
    }
  }

  int binary_search(int key){
    int ok = q;
    int ng = -1;
    while( abs (ok - ng) > 1){
      int mid = (ok + ng) / 2;
      if(solve(mid,key) == 1){
        ok = mid;
      }else{
        ng = mid;
      }
    }
    if(T[ok] == key){
      C ++;
    }
  }

int main(){

  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(int i=0; i<n; i++){
    scanf("%d",&T[i]);
  }

  qsort(T,q,sizeof(int),ascending);
  qsort(S,n,sizeof(int),ascending);  

  for(int i=0; i<n; i++){
    if(i == 0){
      binary_search(S[i]);
    }else{
      if( S[i] > S[i-1] ){
        binary_search(S[i]);
      }
    }
  }

  printf("%d\n",C);

  return 0;
}
