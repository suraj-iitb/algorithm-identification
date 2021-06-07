#include <stdio.h>

int main(){
  int n,q,key,i,j,count=0;
  int S[10000];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    for(j=0;j<n;j++)
      if(S[j]==key){
	count++;
	break;
      }
  }

  printf("%d\n",count);

  return 0;
}
