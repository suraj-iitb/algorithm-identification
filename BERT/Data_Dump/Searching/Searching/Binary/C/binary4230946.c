#include <stdio.h>

#define NOT_FOUND -1
#define MAX 100000

int BinarySearch(int [],int,int);

int main(){
  int n,S[MAX],key,q;
  int sum = 0;
  int i;
  
  scanf("%d",&n);
  for (i = 0;i < n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  for (i = 0;i < q;i++){
    scanf("%d",&key);

    if (BinarySearch(S,n,key) != -1)
      sum++;
  }

  printf("%d\n",sum);
  
  return 0;
}

int BinarySearch(int A[],int n,int key){
  int left = 0,right = n,mid;

  while (left < right){
    mid = (left + right) / 2;

    if (A[mid] == key)
      return mid;

    else if (A[mid] > key)
      right = mid;

    else
      left = mid + 1;
  }

  return NOT_FOUND;
}

