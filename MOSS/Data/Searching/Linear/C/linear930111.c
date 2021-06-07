#include <stdio.h>

#define N 10000
#define Q 500

int main(){
  int S[N],T[Q];
  int n,m,i,j,count=0,flag=0;
  scanf("%d",&n);
  for(i=0; i<n ; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&m);
  for(i=0; i<m ; i++){
    scanf("%d",&T[i]);
  }
  for(i=0; i<m ; i++){
    flag=0;
    for(j=0; j<n ; j++){
      if(flag!=0 && flag!=1)
	continue;
      if(S[j]==T[i]){
	count++;
	break;
      }
    }
  }
  if(count==0) printf("0\n");
  else printf("%d\n",count);
  return 0;
}
