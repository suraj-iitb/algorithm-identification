#include<stdio.h>
int ssearch(int S[], int n, int k)
{
  int i=0;
  S[n]=k;
  
  while(S[i]!=k)i++;
  return i!=n;
}

int main(){
  int i,n,S[10001],q,key,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if( ssearch(S, n, key) )sum++;
  }
  printf("%d\n",sum);
  
  return 0;
}
    

