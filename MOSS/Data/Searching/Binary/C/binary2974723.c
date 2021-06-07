#include <stdio.h>

int A[100000],n;

int search(int t){
  int left=0,right=n,mid;
  while (left<right){
    mid=(left+right)/2;
    if(t==A[mid])return 1;
    if(t>A[mid])left=mid+1;
    else if(t<A[mid])right=mid;
  }
  return 0;
}


int main(){
  int i,ans=0,q,t;

  scanf("%d",&n);

  for(i=0;i<n;i++)
        scanf("%d",&A[i]);

  scanf("%d",&q);

   for(i=0;i<q;i++){
          scanf("%d",&t);
          if(search(t))
              ans++;

     }

printf("%d\n",ans);
  return 0;
}



