#include <stdio.h>

#define N 10000

int S[N],T[N];

int n,q;

int search(int);

int main(){

  int i,j,c=0;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }

  for(i=0; i<q; i++){
   
    if(search(T[i]) == 1) c++;
  }

  printf("%d\n",c);


  return 0;
}

int search(int key){

  int i;
  for(i=0; i<n; i++){
    if(S[i] == key) return 1;
  }

  return 0;
}
