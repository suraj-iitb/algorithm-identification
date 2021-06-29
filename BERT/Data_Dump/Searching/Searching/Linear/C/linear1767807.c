#include <stdio.h>


int S[100000];
int T[100000];


int main(){

  int n,q,i,j,key,count=0;


  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    key = T[i];

    for(j=0;j<n;j++){
      if(S[j] == key){
	count++;
	break;
      }

    }
  }

  printf("%d\n",count);

  return 0;
}
    
