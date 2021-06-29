#include<stdio.h>

#define INFTY 1000000000
 int c=0;
 
 void merge(int*A, int left,int mid,int right){
   int i,j,k,n1,n2;

   
   n1 = mid -left;
   n2 = right -mid;

   int L[n1+1],R[n2+1];

   for(i=0;i<n1;i++)
     L[i] = A[left+i];

   for(i=0;i<n2;i++)
     R[i] = A[mid+i];

   L[n1] = INFTY;
   R[n2] = INFTY;

   i=0;
   j=0;

   for(k=left;k<right;k++){
     c++;
     if(L[i] <= R[j]){
       A[k] = L[i];
       i++;
     }
     else{
       A[k] = R[j];
       j++;
     }
   }
   

}

mergeSort (int*A,int left,int right){
  int mid;
  
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main(){
  int n,i;

  scanf("%d",&n);

  int A[n];

  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  mergeSort(A,0,n);

  for(i=0;i<n;i++){
    if(i!=0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",c);
  

  return 0;
  
}

