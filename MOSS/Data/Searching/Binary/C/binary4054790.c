#include <stdio.h>

int n;
int binarySearch(int A[],int);

int main(){

  int S[1000003],q,i,s=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++)
    {
      if(binarySearch(S,T[i])==1)
	s++;
    }

  printf("%d\n",s);

  return 0;
}

int binarySearch(int A[],int key)
{
  int right=n;
  int left=0;
  int m;
  while(left<right){
    m=(left+right)/2;
    if(A[m]==key){
      return 1;
    }
    else if(A[m]>key){
      right=m;
    }
    else if(A[m]<key){
      left=m+1;
    }
  }
  return 0;
}
    
  
  
  

