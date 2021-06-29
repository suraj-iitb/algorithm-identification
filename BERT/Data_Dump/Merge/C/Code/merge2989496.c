#include<stdio.h>
#define max 500000
#define sent 2000000000

int L[max/2+2],R[max/2+2];
int cnt;

void marge(int A[],int n,int left,int mid,int right){
  int i,j,k;
  int n1 = mid-left;
  int n2 = right-mid;
  for(i=0;i<n1;i++){
    L[i] = A[left +i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1] = R[n2] = sent;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      A[k]=L[i++];
    }
    else{
      A[k]=R[j++];
    }
  }
}


void margesort(int A[],int n,int left,int right){
  if(left+1<right){
    int mid = (left + right)/2;
    margesort(A,n,left,mid);
    margesort(A,n,mid,right);
    marge(A,n,left,mid,right);
  }
}


int main(){
  int A[max],i,n;
  cnt=0;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  margesort(A,n,0,n);

  printf("%d", A[0]);
  for(i=1;i<n;i++){
    printf(" %d", A[i]);
  }
printf("\n" );
  printf("%d\n",cnt);

  return 0;
}

