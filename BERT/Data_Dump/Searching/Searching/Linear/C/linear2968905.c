#include<stdio.h>

#define N 10000
#define Q 500

int main(){
  int S[N]={0};
  int T[Q]={0};
  int U[5000]={0};
  int i,j,k=0,n,q,count=0,F;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);

  for(i=0;i<n;i++){
    F=0;
    for(j=0;j<q;j++){
      for(k=0;k<count;k++){
	if(S[i]==U[k]) F=1;
      }
      if(S[i]==T[j]&&F==0){
	U[k]=S[i];
	k++;
	count++;
      }
    }
  }
  
  printf("%d\n",count);
  
  return 0;
}

