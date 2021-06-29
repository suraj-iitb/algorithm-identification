#include <stdio.h>
#define MAX 500000
#define INFTY 2000000000

void merge(int[], int, int, int);
void mergeSort(int[] ,int,int);

int L[MAX/2+2],R[MAX/2+2],count;
int main(){
  
  int n,i,S[MAX];
  count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){

    scanf("%d",&S[i]);
    if(S[i] >= INFTY){
      return 1;
    }
  }

  mergeSort(S,0,n);

  for(i=0;i<n;i++){
    if( i ) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
  printf("%d\n",count);


  return 0;
}

void merge(int A[],int left,int mid,int right){

  int i,j,k,n1,n2;
  n1 = mid -left;
  n2 = right - mid;

  for(i=0;i<n1;i++) L[i] = A[left + i];
  for(i=0;i<n2;i++)  R[i] = A[mid + i];
  L[n1] = R[n2]= INFTY;
  i = j = 0;
  for(k=left;k<right;k++){ count++;
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
void mergeSort(int A[], int left, int right){
    int mid;

    if(left+1<right){
 
      mid = (left + right)/2;
      mergeSort(A, left, mid);
      mergeSort(A, mid, right);
      merge(A, left, mid, right);
	
    }
  }
