#include <stdio.h>
#define N 10000
int linearSearch(int,int);
int S[N];
int main(){
  int i,j=0,n,q,T[N],cunt = 0;
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&T[i]);
  }
  
  /*
  for(i = 0;i < n;i++){
    for(j = 0;j < q;j++){
      if(S[i] == T[j]){
	T[j] = N+1;
	cunt++;
      }
    }
  }
  */
  for(i = 0;i < q;i++){
    cunt += linearSearch(T[i],n);
  }
  
  printf("%d\n",cunt);
  return 0;
}
int linearSearch(int key,int n){
  int i,j;
  for(i = 0;i < n;i++){
      if(S[i] == key){
	return 1;
      }
  }
  return 0;
}

