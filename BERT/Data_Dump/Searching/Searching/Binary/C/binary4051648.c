#include<stdio.h>
int serch(int,int,int[]);

int main(){
  int S[100000];
  int t;
  int i,key,n,q,sum=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    if(serch(n,t,S)==1){
      sum++;
    }
  }
  printf("%d\n",sum);
  return 0;
}

int serch(int n,int key,int S[]){
  int left=0,mid,right=n;

   while(left<right){
     mid=(left+right)/2;

     if(key==S[mid]){
       return 1;
     }
     if(key>S[mid]){
       left=mid+1;
     }
     else if(key<S[mid]){
        right=mid;
       }
   }
     return 0;
}

  

