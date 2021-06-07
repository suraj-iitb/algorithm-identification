#include <stdio.h>

int linersearch(int *,int key);
int n;
int q;
int T[10000];

int main(){
  int i,j;
  int c=0;
  int S[10000];
  int Q[10000];
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
  
  for(i=0; i<n; i++){
    c += linerSearch(Q,S[i]);
  }
  printf("%d\n",c);
  return 0;
}

int linerSearch(int *A,int key){
  int i,j;
  A[q] = key;
  for(i=0; i<q; i++){
    if(A[i]==key){
      for(j=0;j < n;j++){
	if(A[i]==T[j]) {
	  //  printf("same %d, ",T[j]);
	  return 0;
	}
      }
      T[i] = key;
      return 1;
    }
  }
  return 0;
}


