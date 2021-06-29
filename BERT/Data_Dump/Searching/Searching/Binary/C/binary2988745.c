#include <stdio.h>

int linersearch(int *,int key);
int n;
int q;
int T[100000];

int main(){
  int i,j;
  int c=0;
  int S[100000];
  int Q[100000];
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&Q[i]);
  }
  for(i=0; i<n; i++){
    T[i] = -1;
  }
  
  for(i=0; i<q; i++){
    c += linerSearch(S,Q[i]);
  }
  printf("%d\n",c);
  return 0;
}

int linerSearch(int *A,int key){
  int i,j,m;
  int l = 0;
 int  r = n;
 while( l< r ){
    m = (l + r)/ 2;
    if(A[m]==key){
      return 1;
    }else if(key < A[m]){
      r = m;
    }else{
      l = m + 1;
    }
  }
  return 0;
  
}


