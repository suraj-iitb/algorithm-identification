#include <stdio.h>
#define N 100000
#define Q 50000

int binarySearch(int);

int S[N], n;

int main()
{
  int i, C=0, result, q, T[Q];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
 
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    result=binarySearch(T[i]);
    if(result==1) C++;
  }
 printf("%d\n",C);

  return 0;
}

int binarySearch(int key)
{
  int left=0, right=n, mid;

  while(left<right){
    mid=(left+right)/2;
    if(S[mid]==key) return 1; 
    else if(key<S[mid])  right=mid;
    else  left=mid+1;
  }
  return 0;
}




 
  
  
