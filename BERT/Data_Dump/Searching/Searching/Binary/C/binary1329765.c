#include<stdio.h>
int main()
{
  int j,i,n,q,C=0,mid=0,r=0,l=0,k=0;
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
    l=0;
    r=n;
    while(l<r){
      mid=(l+r)/2;
      if(S[mid]==T[i]){
	C++;
        c[k]=S[mid];
        k++;
	break;
      }
      if(T[i]>S[mid]){
	l=mid+1;
      }
      else if(T[i]<S[mid]){
	r=mid;
      }
    }
  }
  printf("%d\n",C);
  return 0;
}
