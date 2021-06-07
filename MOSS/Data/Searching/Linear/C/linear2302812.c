#include <stdio.h>
#define N 10000
#define Q 500
int linearSearch();
int i,j,n,q,S[N],T[Q],c=0;
int main(){
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);
 printf("%d\n",linearSearch());
  return 0;
}

int linearSearch(){

  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i]==S[j]){
	c++;
      break;
      }
    }
  }
  return c;
}
