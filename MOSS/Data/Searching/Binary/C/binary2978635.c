#include<stdio.h>
int main()
{
  int j,i,n,q,C=0,mid=0,right=0,left=0,k=0;
  int S[100000],T[50000],c[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(S[mid]==T[i]){
    C++;
        c[k]=S[mid];
        k++;
    break;
      }
      if(T[i]>S[mid]){
    left=mid+1;
      }
      else if(T[i]<S[mid]){
    right=mid;
      }
    }
  }
  printf("%d\n",C);
  return 0;
}

