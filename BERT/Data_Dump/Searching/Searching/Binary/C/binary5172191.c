#include <stdio.h>

int main(){
  int a,n,q,i,count,right,left,mid;
  int S[100000],T[50000];
  count=0;

  //*数列Sの個数*//
  scanf("%d",&n);
  //*数列Sの要素*//
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  while(1){
    scanf("%d",&q);
    for(i=0;i<q;i++){
      left=0;
      right=n;
      scanf("%d",&T[i]);
      a=T[i];
      while(left<right){
        mid=(left+right)/2;
        if(a==S[mid]){
          count++;
          break;
        }
        if(a>S[mid]){
          left=mid+1;
        }                                                                             else{
          right=mid;
        }                                                                           }
    }
    printf("%d\n",count);
    break;
  }
                                                                                return 0;
}  
