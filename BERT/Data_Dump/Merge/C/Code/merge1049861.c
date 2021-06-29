#include <stdio.h>
  
#define N 500001
#define S 10000000333
  
void Merge(int*,int, int, int);
void Merge_Sort(int*,int, int);
  
int c = 0;
main(){
  
int n,i,A[N];
  
scanf("%d",&n);
  
for(i = 0; i < n ; i++) scanf("%d",&A[i]);
  
Merge_Sort(A,0,n);

for(i = 0;i < n;i++){
    printf("%d",A[i]);
    if(i < n-1){
      printf(" ");
    }
  }
     
  printf("\n%d\n",c);
   
  return 0;
     
} 
 
  
  
void Merge_Sort(int* A,int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right) / 2;
    Merge_Sort(A,left, mid);
    Merge_Sort(A,mid, right);
    Merge(A,left, mid, right);
  }
  }
  
void Merge(int* A,int left,int mid,int right){
  int n1,n2;
  int i,j,k;
  int L[N],R[N];
     
  n1 = mid - left;
  n2 = right - mid;
     
  for(i = 0; i < n1; i ++){
    L[i] = A[left + i];
  }
  for(i = 0; i < n2; i ++){
    R[i] = A[mid + i];
  }
     
  L[n1] = S;
  R[n2] = S;
     
  i = 0;
  j = 0;
    
  for (k = left; k <= right-1; k ++)
    {
      c++;
      if (L[i] <= R[j]){
    A[k] = L[i];
    i++;
      }else{
    A[k] = R[j];
    j++;
      }
    }
}
