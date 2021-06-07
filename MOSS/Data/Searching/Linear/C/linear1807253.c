#include<stdio.h>
#define N 10000
#define Q 500

int main(){
  int i,j,n,q;
  int S[N],T[Q],count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
    for(i=0;i<n;i++){
      if(S[i]==T[j]){
	count++;
	break;
      }
    }
  }
    printf("%d\n",count);
    return 0;
}
