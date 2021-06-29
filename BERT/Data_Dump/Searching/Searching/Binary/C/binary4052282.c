#include<stdio.h>
#define NOT_FOUND -1

int binarySearch(int *, int, int);

int main()
{
  int s[100000],t[50000],n,i,j,m,ret,cnt = 0;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&m);
  for(i = 0; i < m; i++){
    scanf("%d",&t[i]);
  }

  for(j = 0; j < m; j++){
    ret = binarySearch(s,n,t[j]);
    if(ret != NOT_FOUND){
      cnt++;
    }
  }
  printf("%d\n",cnt);
  
  return 0;
}

int binarySearch(int A[], int n, int key)
{
  int left,right,mid;

  left = 0;
  right = n;

  while(left < right){
    mid = (left + right) / 2;
    if(A[mid] == key)return mid;
    else if(key < A[mid])right = mid;
    else left = mid + 1;
  }

  return NOT_FOUND;
}

