#include<stdio.h>
#include<stdlib.h>


int Merge(int,int,int);
void MergeSort(int,int);

int A[500000],L[500000],R[500000];
int c=0;
int INFTY=1000000000;

int Merge(int left, int mid, int right){
  int i,k,n1,n2,j;

n1 = mid - left;
 for(i=0;i<n1;i++){
   L[i]=A[left+i];
 }
 L[n1]=INFTY;

n2 = right - mid;

 for(i=0;i<n2;i++){
   R[i] = A[mid + i];
 }
 R[n2]=INFTY;
  

 i=0;
 j=0;
 for( k = left;k< right;k++){
   c++; 
  if(L[i] <= R[j]){
     A[k] = L[i];
     i = i + 1;
   }
  else{
    A[k] = R[j];
	 j = j + 1;
       }
 }

}
   void MergeSort(int left, int right){
     int mid;
     if( left+1 < right){
   mid = (left + right)/2;
   MergeSort( left, mid);
     MergeSort( mid, right);
     Merge( left, mid, right);
     }}

   int main(){
     int i;
     int n;
 
     scanf("%d", &n);
     for(i=0;i<n;i++){
	 scanf("%d", &A[i]);
       }
 
     MergeSort(0, n);
 
     for(i=0;i<n-1;i++){       
	 printf("%ld ", A[i]);
       }
     printf("%d\n", A[n-1]);
     printf("%d\n",c);
 
     return 0;
   }
