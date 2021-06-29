#include<stdio.h>
#include<limits.h>
#define N 500000
void Merge(int[],int,int,int);
void MergeSort(int[],int,int);
int c;
int main(){
  int x,i,A[N];
  scanf("%d",&x);
  for(i = 0 ; i < x ; i++)
    scanf("%d",&A[i]);
  MergeSort(A,0,x);
  for(i = 0 ; i < x-1 ; i++)
    printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",c);
  return 0;
}

void Merge(int A[],int left,int mid,int right){
  int p1,p2,i,j,k;
  p1 = mid - left;
  p2 = right - mid;
  int L[p1 + 1],R[p2 + 1];
  for(i = 0 ; i < p1 ; i++)
    L[i] = A[left + i];
  for(i = 0 ; i < p2 ; i++)
    R[i] = A[mid+i];
    L[p1] = INT_MAX;   
    R[p2] = INT_MAX;   
    i = 0;
    j = 0;
    for(k = left ; k < right ; k++){
      c++;
      if(L[i] <= R[j]){
	A[k] =L[i];
	i = i+1;
      }
      else{
	A[k] = R[j];
	j = j+1;
      }
    }
}       


void MergeSort(int A[],int left,int right){
  int mid;  
  if(left+1<right) {
    mid=(left+right)/2;
    MergeSort(A,left,mid);    
    MergeSort(A,mid,right);    
    Merge(A,left,mid,right);    
  }
}
