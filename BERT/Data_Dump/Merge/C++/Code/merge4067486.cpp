#include<stdio.h>

#define INFINITY 2000000001
#define N 500000

int merge(int *, int ,int ,int);
void mergeSort (int *,int ,int);

int cnt=0;

int main(){
  int Merge[N];
  int num,i;
  int right,left,mid;

  scanf("%d",&num);
  for(i=0;i<num;i++) scanf("%d",&Merge[i]);

  right = num;
  left = 0;
  mid = (right + left) / 2;

  mergeSort(Merge,left,right);

  //printf("num: %d\n",num);
  
  for(i=0;i<num;i++){
    if(i) printf(" ");
    printf("%d",Merge[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  
  return 0;

}

int merge(int A[],int left,int mid,int right){
  int i,j,k,n1,n2;
  int R[N],L[N];

  //printf("wa-i\n");
  
  n1 = mid - left;
  n2 = right - mid;
  //L[0...n1], R[0...n2] を生成
  for (i = 0;i<= n1-1;i++)
    L[i] = A[left + i];
  for (i = 0;i<= n2-1;i++)
    R[i] = A[mid + i];
  // printf("aaaa\n");
  L[n1] = INFINITY;
  R[n2] = INFINITY;
  i = 0;
  j = 0;
  for (k = left;k<=right-1;k++){
    cnt++;
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else {
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int A[],int left,int right){
  int mid;
  int i;
  //printf("%d  %d\n",left,right);
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    //printf("wa-iwa-i%d  %d\n",left,right);
    mergeSort(A, mid, right);
    //printf("wa-iwa-iwa-i\n");
    merge(A, left, mid, right);
  }
}


