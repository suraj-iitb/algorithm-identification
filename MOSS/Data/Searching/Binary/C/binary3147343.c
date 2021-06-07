#include<stdio.h>

 int B(int n,int S[],int key){
      int i,right,left,mid;
      left=0;
      right=n;
      while(left<right){
             mid=(left+right)/2;
             if(S[mid]==key)return 1;
             else if(key<S[mid])right=mid;
             else left=mid+1;
             }
      return 0;
      }
 
 
 int main(){
      int i,j,n,q,S[100000],T,count=0,key;
      scanf("%d",&n);
      for(i=0;i<n;i++){
            scanf("%d",&S[i]);
            }
      scanf("%d",&q);
      for(i=0;i<q;i++){
            scanf("%d",&T);
            key=B(n,S,T);
            if(key!=0)count++;
            }
      printf("%d\n",count);
      return 0;
      }
