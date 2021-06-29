#include<stdio.h>
#include<stdlib.h>

#define MAX 500001
#define INFTY 2000000000

int count =0; 
void marge (int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  int L[MAX/2+1],R[MAX/2+1];
  
  n1 = mid - left;
  n2 = right - mid;
  
  for(i=0; i<n1; i++) L[i]= A[left+i];
  for(i=0; i<n2; i++) R[i]= A[mid+i];

  /* printf("確認\n");
  for(i=0; i<n1; i++)printf("%d ",L[i]);
  printf("\n");
  for(i=0; i<n2; i++)printf("%d ",R[i]);
  printf("\n");
  printf("確認終了\n");
  */
    
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = j = 0;
  
  for(k=left; k < right; k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
  }
}

void margeSort(int A[],int left,int right){
  int mid;
  // printf("mragrSort\n");
  if (left+1 < right){
    mid = (left + right)/2;
    margeSort(A,left,mid);
    margeSort(A,mid,right);
    marge(A,left,mid,right);
  }
}

int main(){
  int i,j,n;
  int A[MAX];
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  //  printf("マージソート開始\n");
  margeSort(A,0,n);
  
  for(i=0; i<n; i++){
    if(i>=1)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

