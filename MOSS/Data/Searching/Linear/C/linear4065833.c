#include<stdio.h> 

#define NMAX 10000
#define QMAX 500

int main(){
  int i,j,k,l,n,q,count=0,S[NMAX],T[QMAX];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }
  for(k=0;k<j;k++){
    for(l=0;l<i;l++){
      S[i]=T[k];
      if(S[l]==T[k]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}
  

