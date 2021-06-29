#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Merge(int *,int,int,int);
void MergeSort(int *,int,int);
int cnt=0;

int main(){
  int i,n,left,right;
  int *a;

  scanf("%d",&n);
  a=(int *)malloc(sizeof(int)*n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  right=n;
  left=0;

  MergeSort(a,left,right);

  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",cnt);

  free(a);


  return 0;

}


void Merge(int *A,int left,int mid,int right){
  int *L,*R,i,k,j,n1,n2;
  // for(i=0;i<10;i++) printf("%d \n",A[i]);

  n1 = mid - left;
  n2 = right - mid;

  L=(int *)malloc(sizeof(int)*(n1+1));
  R=(int *)malloc(sizeof(int)*(n2+1));


  for( i = 0 ; i <= n1-1; i++){
    L[i] = A[left + i];
  }
  for( i = 0 ; i <= n2-1; i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFINITY;
  R[n2] = INFINITY;
  i = 0;
  j = 0;

  for(k = left ; k<=right-1; k++){
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      cnt++;
    }
    else {
      A[k] = R[j];
      j = j + 1;
      cnt++;
    }
  }
  free(L);
  free(R);
}

void MergeSort(int *A,int left,int right){
  int i,mid;

  if (left+1 < right){
    mid = (left + right)/2;
    MergeSort(A,left,mid);
    MergeSort(A,mid,right);
    Merge(A,left,mid,right);
  }

}
