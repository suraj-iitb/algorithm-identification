#include<stdio.h>
int main(){
  int n,q;
  int S[10000];
  int T[500];
  int i,j;
  int count=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }
  
  for(j=0;j<q;j++){
    for(i=0;i<n;i++){
      if(S[i]==T[j]){ count++; break;
      }  
    }
  }
  printf("%d\n",count);
  return 0;
}
