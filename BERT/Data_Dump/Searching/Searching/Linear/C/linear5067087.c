#include<stdio.h>

int main(){
  int S[10000],T[10000];
  int i,j,n1,n2,c=0,status=0;

  scanf("%d",&n1);
  for(i=0;i<n1;i++)scanf("%d",&S[i]);
  scanf("%d",&n2);
  for(i=0;i<n2;i++)scanf("%d",&T[i]);

  for(i=0;i<n2;i++){
    for(j=0;j<n1;j++){
      if(T[i] == S[j]){
	c++;
	status = 1;
	break;
      }
    }
    if(status == 1)continue;
  }

  printf("%d\n",c);

  return 0;
}
  

