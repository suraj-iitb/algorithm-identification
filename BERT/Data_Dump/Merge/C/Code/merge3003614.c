#include <stdio.h>
int C[500001];
int A[500001];
int count=0;
void merge(int a[],int left,int right);
int main(){
  int i,n;
 
  scanf("%d",&n);
  for(i=0; i < n ; i++){
    scanf("%d",&A[i]);
  }
  merge(A,0,n-1);
  for(i=0; i < n ; i++){
    if(i < n-1){
    printf("%d ",A[i]);
    }
    else{
      printf("%d",A[i]);
    }
  }
  printf("\n%d\n",count);
  return 0;
}

void merge(int A[],int left,int right){
  int mid,i,j,p;
  if(right <=left)return;
  mid=(left+right)/2;
  merge(A,left,mid);
  merge(A,mid+1,right);

  for(i=left; i <= mid;i++){
    C[i]=A[i];
  }
  j=right;
  for(i=mid+1;i <=right;i++){
    C[i]=A[j];
    j--;
  }
  j=right;
  i=left;
  for(p=left;p<=right;p++){
    if(C[i]<=C[j]){
      A[p]=C[i++];
      count++;
    }
    else{
      A[p]=C[j--];
      count++;
    }
  }
}

