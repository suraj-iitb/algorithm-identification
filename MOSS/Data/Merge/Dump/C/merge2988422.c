#include<stdio.h>
#define SENTINEL 1000000000
#define MAX 5000000

int  N,c=0,L[MAX/2+2], R[MAX/2+2];
void Merge(int A[],int left,int mid,int right){
   int i,j,k,n1,n2;
   n1 = mid - left;
   n2 = right - mid;

   for(i=0;i<n1;i++)L[i] = A[left + i];
   for (i=0;i<n2;i++)R[i] = A[mid + i];

   L[n1] = SENTINEL;
   R[n2] = SENTINEL;
   i = 0;
   j = 0;
   for(k=left;k<right;k++){
     c++;
     if(L[i]<=R[j]){
       A[k]=L[i];
       i = i + 1;
     }
     else {
       A[k] = R[j];
       j = j + 1;
     }
   }
 }

void Mergesort(int A[],int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    Mergesort(A, left, mid);
  Mergesort(A, mid, right);
  Merge(A, left, mid, right);
  }
}

int main(){

  int i,A[MAX];

   scanf("%d",&N);
   for(i=0;i<N;i++){
    scanf("%d",&A[i]);

   }

   Mergesort(A,0,N);

   for(i=0;i<N;i++){
     if(i!=N-1)printf("%d ",A[i]);
     else printf("%d",A[i]);
   }
   printf("\n");
   printf("%d\n",c);
   return 0;
 }
