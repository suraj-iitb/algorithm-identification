#include<stdio.h>
#include<stdlib.h>

int binarySearch(int);

int n,*S;

int main()
{
  int q,i,x,c = 0;
  int *T;

  scanf("%d",&n);
  S = (int *)malloc(sizeof(int) * n);
  if(S == NULL) exit(1);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  T = (int *)malloc(sizeof(int) * q);
  if(T == NULL) exit(1);
  for(i = 0;i < q;i++){
    scanf("%d",&T[i]);
    }

   for(i = 0;i < q;i++){
    x = binarySearch(T[i]);
    if(x != -1) c ++;
   }
   printf("%d\n",c);
   return 0;
}

int binarySearch(int key)
{
  int left = 0;
  int right = n;
  int mid;

  while(left < right){
    mid = (left + right)/2;

    if(S[mid] == key) return mid;
    else if(key < S[mid]) right = mid;
    else left = mid + 1;
  }
  return -1;
}
