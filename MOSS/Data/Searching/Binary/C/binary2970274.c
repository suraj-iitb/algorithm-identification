#include <stdio.h>

#define N_MAX 100000
#define Q_MAX 50000

int main(){
  int n,q,i,j;
  int S[N_MAX];
  int T[Q_MAX];
  int left,right,mid;
  int cont=0;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
  }

  //----------------
  for(i=0; i<q; i++){
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(S[mid]==T[i]){
	cont++;
	break;
      }else if(T[i]<S[mid]){
	right = mid;
      }else left = mid+1;
    }
  }

  printf("%d\n",cont);
  return 0;
}

