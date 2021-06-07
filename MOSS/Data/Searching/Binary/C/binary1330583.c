#include<stdio.h>
int binarySearch(int);
int S[100000],n;

int main()
{

  int i=0,q,T[50000],j=0,c=0;

  scanf("%d",&n);

  while(i < n){
    scanf("%d",&S[i]);
    i++;
  }
  
  scanf("%d",&q);
  
  while(j < q){
    scanf("%d",&T[j]);
    j++;
  }
  
  for(i = 0;i < q;i++){
  c += binarySearch(T[i]);
  }
  printf("%d",c);
  printf("\n");
  return 0;
}

int binarySearch(int key)
{
  int left = 0;
  int right = n;
  int mid;
  while(left < right){
    mid = (left + right) / 2;
    if(S[mid] == key) return 1;
    else if(key < S[mid]) right = mid;
    else left = mid + 1;
  }
    return 0;
}
