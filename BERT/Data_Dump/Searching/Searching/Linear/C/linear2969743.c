#include<stdio.h>
int main(){
  int n,q,i,c=0,j;
  
  scanf("%d",&n);
  
  int S[n];
  
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  
  int T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(T[i]==S[j]){
	c++;
	break;
      }
    }
  }
  printf("%d\n",c);
  
  return 0;

}

