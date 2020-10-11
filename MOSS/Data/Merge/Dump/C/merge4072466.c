#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <stdint.h>
#include <inttypes.h>

#define M 500000
#define INFTY 1000000001

int count;

void merge(int *, int ,int ,int );
void mergeSort(int *, int , int );
  
int main(){
  int S[M];

  int i,j,n;
  int l, mid , r;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  l=0;
  r=n;
  
  mergeSort(S,l,r);

  
  printf("%d",S[0]);
  for(i=1;i<n;i++)
    printf(" %d",S[i]);
  printf("\n");
  printf("%d\n",count);
  
  return 0;

}


void merge(int *A, int left, int mid,int right)
{
  int i,j,k,n1,n2;
  int L[M],R[M];

  
  n1 = mid - left;
  n2 = right - mid;


  
  /* L[0...n1], R[0...n2] を生成*/
  for (i = 0;i<n1;i++)
      L[i] = A[left + i];
  for (i = 0;i< n2;i++)
    R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
    for (k = left;k<right;k++){
      count++;
      if (L[i] <= R[j]){
       A[k] = L[i];
      
       i = i + 1;
     }
     else{ 
       A[k] = R[j];
       j = j + 1;
     }
    }

 }
 
void mergeSort(int *A, int left, int right)
   {
     int mid;


     
     if (left+1 < right){
       mid = ((left) + (right))/2;
       mergeSort(A, left, mid);
       mergeSort(A, mid, right);
       merge(A, left, mid, right);
     }
   }

