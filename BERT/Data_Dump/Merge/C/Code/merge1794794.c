#include <stdio.h>
#include <stdlib.h>
void merge(int [],int,int,int);
void mergeSort(int [],int,int);
int cnt;
int main(){
  int S[500000],i,n;
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
 
  mergeSort(S,0,n);

  for(i=0;i<n;i++){
    if(i==0) printf("%d",S[i]);
    else if(i==n-1)  printf(" %d\n",S[i]);
    else printf(" %d",S[i]);
  }
  printf("%d\n",cnt);

  return 0;
}

void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  double *L,*R;

  n1=mid-left;
  n2=right-mid;

  L=(double*)malloc((sizeof(double))*(n1+1));
  R=(double*)malloc((sizeof(double))*(n2+1));

  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }

  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1]=1.0/0.0;
  R[n2]=1.0/0.0;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else {
      A[k]=R[j];
      j++;
    }

  }
  
  free(L);
  free(R);

}
void mergeSort(int A[],int left,int right){
  int mid;
  
  if(left+1<right){ mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }

}
