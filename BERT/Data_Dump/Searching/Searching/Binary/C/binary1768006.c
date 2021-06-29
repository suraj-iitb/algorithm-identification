#include <stdio.h>

int A[100000];
int n;

int binarySearch(int key)
{
  int left = 0;
  int right = n;
  int mid;
  while (left < right){
    mid = (left + right) / 2;
    if (A[mid] == key)
      {

	return 1;
      }
    if (key < A[mid])
      {
	right = mid;
      }
    if (key > A[mid])
      {
	left = mid + 1;
      }
  }
  return 0;
}
      
  int main ()
  {

    int i,n2,keyword,judge=0;
    int M[100000];
  scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&A[i]);
    }
  
    scanf("%d",&n2);
      for(i=0;i<n2;i++){
	scanf("%d",&M[i]);
      }
      
 
      for(i=0;i<n2;i++){    
    if(binarySearch(M[i]))
      {

	judge++;
      }
      }
      printf("%d\n",judge);
    return 0;
}
