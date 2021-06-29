#include <stdio.h>

#define NMAX 100000
#define QMAX 50000

int BinarySearch (int *, int, int);

int main (void)
{
  int i,n,q,result,count=0,arrayS[NMAX],arrayT[QMAX];

  scanf ("%d",&n);
  for (i = 0 ; i < n ; i++){
    scanf ("%d",&arrayS[i]);
  }
  scanf ("%d",&q);
  for (i = 0 ; i < q ; i++){
    scanf ("%d",&arrayT[i]);
  }

  for (i = 0 ; i < q ; i++){
    result = BinarySearch(arrayS,arrayT[i],n);
    if (result != -1)
      count++;
  }
  printf ("%d\n",count);
  return 0;
}

int BinarySearch (int *S, int key, int n)
{
  int left,right,mid;

  left = 0;
  right = n;

  while(left < right){
    mid = (left + right) / 2;
    if (S[mid] == key)
      return mid;
    else if (key < S[mid])
      right = mid;
    else
      left = mid + 1;
  }
  
  return -1;
}
