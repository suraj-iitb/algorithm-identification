#include <stdio.h>
int main()
{
  int n,i,j,q,key,S[100000],T[1000];
  int cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&S[i]);
}
  scanf("%d",&q);
  for(j=0;j<q;j++){
  scanf("%d",&T[j]);
}
  for(i=0;i<q;i++){
    for(j=0;j<n;j++){
      if(S[j]==T[i]){
        cnt++;
        break;
      }
    }
  }
  printf("%d\n",cnt);
  return 0;

}

