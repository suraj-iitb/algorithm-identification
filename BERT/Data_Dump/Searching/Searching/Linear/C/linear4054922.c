#include <stdio.h>
#define N 10000

int main(){
  int n,q,i,j,S[N],T[N],count=0,status;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    status = 0;
    
    if(i!=0){
      for(j=i-1;j<0;j--){
	if(T[i] == T[j]) status = 1;
      }
    }
    
    if(status == 0){
      for(j=0;j<n;j++){
	if(T[i] == S[j]){
	  count += 1;
	  break;
	}
      }
    }
  }
  
  printf("%d\n",count);
  
  return 0;
}

