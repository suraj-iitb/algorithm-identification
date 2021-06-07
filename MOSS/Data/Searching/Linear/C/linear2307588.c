#include <stdio.h>
#define MAX 100000
int linearSearch(int,int);

int S[MAX],T[MAX];

int main(){
  int n,q,i,j,k,count=0;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
  }

  for(i = 0; i < q; i++){
    count = count + linearSearch(T[i],n);
    /*printf("%d\n",count);*/
  }
  
  printf("%d\n",count);

  return 0;
}

int linearSearch(int key,int n){
  int i;
  for(i = 0; i < n; i++){
    if(S[i] == key){
      return 1;
    }
  }
  return 0;
}
