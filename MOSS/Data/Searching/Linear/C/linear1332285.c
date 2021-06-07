#include<stdio.h>
int main(){
  int n1,n2,S[10000],T[100000];
  int i,j,count=0;

  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&S[i]);

  }
  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&T[i]);

  }
  for(i=0;i<n2;i++){
    for(j=0;j<n1;j++){
      if(T[i]==S[j]){count++;break;}
    }
  }
  printf("%d\n",count);
  return 0;
}
