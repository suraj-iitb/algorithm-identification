#include <stdio.h>

void Merge(int, int, int);
void Merge_Sort(int, int);
    
int A[500000],count=0;

main()
{
  int n,i;
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  
  
  Merge_Sort(0,n);
  
  for(i = 0; i < n; i++){
    printf("%d",A[i]);
    if(i != n-1){
      printf(" ");
    }
  }
  
  printf("\n%d\n",count);
  return 0;
  
}


void Merge(int left, int mid, int right)
{


  int  n1 = mid - left,
    n2 = right - mid;
  
  int L[n1+1],R[n2+1];
  int i,j,k;

  for(i = 0; i < n1; i++){

    L[i] = A[left + i];
  }
  for(i = 0; i < n2; i++){
   
    R[i] = A[mid + i];
  }
  
  L[n1] = 1000000000+1;
  R[n2] = 1000000000+1;

i = 0;
  j = 0;
  for(k = left; k < right; k++){

    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else {
      A[k] = R[j];
      j = j + 1;
    }
    count++;
  }
}

void Merge_Sort(int left, int right){
  int mid; 
  
  if(left+1 < right){
    mid = (left + right)/2;
    Merge_Sort(left, mid);
    Merge_Sort(mid, right);
    Merge(left, mid, right);
  }
}
