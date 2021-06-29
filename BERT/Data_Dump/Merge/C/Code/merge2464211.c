#include<stdio.h>
#define N 500000

int A[N],B[N],count=0;

void Mergesort(int *A,int left,int right){

  int i,j,k,mid;
  if(right > left){

    mid=(right+left)/2;
    Mergesort(A,left,mid);
    Mergesort(A,mid+1,right);

    for(i=mid+1;i>left;i--)
      B[i-1] = A[i-1];

    for(j=mid; j<right; j++)
      B[right+mid-j]=A[j+1];

    for(k=left; k<=right; k++){
      A[k] = (B[i]< B[j])?B[i++]:B[j--];
      count++;
    }
  }
}
 
int main(void){
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  Mergesort(A,0,n-1);
  for(i=0;i<n-1;i++)
    printf("%d ",A[i]);
  printf("%d\n%d\n",A[n-1],count);
  return 0;
}
