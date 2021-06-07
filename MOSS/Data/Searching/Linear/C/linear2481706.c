#include<stdio.h>
#include<stdlib.h>



int main(){
  int i,n,q,j,count=0;
  int *S;
  scanf("%d",&n);
  S=malloc((n+1)*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&S[n]);
    j=0;
    while(j!=n){
      if(S[j]==S[n]){
        count++;
        break;
      }
      j++;
    }
  }
  printf("%d\n",count);
  return 0;
}
