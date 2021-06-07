#include<stdio.h>
int main(){
  int i,j,count=0,n1,n2;
  scanf("%d",&n1);
  int S[n1];
  for(i=0;i<n1;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&n2);
  int T[n2];
  for(i=0;i<n2;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<n2;i++){
    for(j=0;j<n1;j++){
      if(S[j]==T[i]){
	count++;
	break;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

