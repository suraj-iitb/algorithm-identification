#include<stdio.h>                                                                      
int i,j,left,right,mid,c=0;                                                            
int binarysearch(int t,int S[],int n)
{
   left=0;//左端
   right=n;//右端
  while(left < right){
    mid = (left + right) / 2;
    if(S[mid]==t){
      c++;
      break;
    }
    else if(t<S[mid])
      right=mid;
    else
      left = mid + 1;
  }
  return 0;
}
int main()
{
  int n,q;
  scanf("%d",&n);
  int S[n];
  for(i=0; i<n; i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  int T[q];
  for(i=0; i<q; i++){
    scanf("%d",&T[i]);
    binarysearch(T[i],S,n);
  }
  printf("%d\n",c);
  return 0;
}
                                                                                                                                                                                                                                                                     

