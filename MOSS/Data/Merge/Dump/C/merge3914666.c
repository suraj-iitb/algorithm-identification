#include<stdio.h>

#define SENTINEL 2000000000

int cnt=0;

void merge(int *A,int left,int mid,int right)//分割した配列を小さい順に結合
{
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1],R[n2];
  int k,i,j;
  for (i=0;i<n1;i++) L[i] = A[left + i];
  for (i=0;i<n2;i++) R[i] = A[mid + i];
  L[n1] = SENTINEL;//EOF
  R[n2] = SENTINEL;//EOF
  i = 0;
  j = 0;
  for(k=left;k<right;k++){//iが左の要素番号,jが右の要素番号
    cnt++;//比較するたびcntをインクリメント
    if(L[i]<=R[j]){//左が小さい場合
      A[k] = L[i];
      i=i+1;
    }else{ //右が小さい場合
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int *A,int left,int right)
{
  int mid;
  if(left+1<right){//二分探索のように左端が右端を超えたら終了
    mid = (left + right)/2;
    mergeSort(A, left, mid);//左半分で再帰
    mergeSort(A, mid, right);//右半分で再帰
    merge(A, left, mid, right);//結合
  }
}

int main(void)
{
    int n,i;
    int A[500001];
    int left,right;
    
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&A[i]);
    left=0;
    right=n;
    mergeSort(A,left,right);
    for(i=0;i<n;i++){
      if(i!=0) printf(" ");
      printf("%d",A[i]);
    }
    printf("\n%d\n",cnt);
    
    return 0;
}
