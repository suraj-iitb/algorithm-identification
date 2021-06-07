#include<stdio.h>
#define N 100000
#define Q 50000
int binarySearch(int);
int n,S[N];
int main()
{
  int q,i,j,count=0,T[Q],key;

  scanf("%d",&n);
  for(i=0;i<=n-1;i++){
    scanf("%d",&S[i]);
}

  scanf("%d",&q);
  for(j=0;j<=q-1;j++){
    scanf("%d",&T[j]);
    if(binarySearch(T[j])==1)
    count++;
}
 
 
 printf("%d\n",count);
 return 0;
}
int binarySearch(int key)
{
  int left=0,right=n,mid;
  while(left<right){
    mid=(left+right)/2;
    if(S[mid]==key){
     return 1;
    }
    else if(key<S[mid]){ 
     right=mid;
    }
    else if(key>S[mid]){
     left=mid+1;
    }
  }
  
return 0;
}
