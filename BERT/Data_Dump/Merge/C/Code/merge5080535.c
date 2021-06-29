#include<stdio.h>
#include<stdlib.h>
#define MAX 500000/*n<=500,000*/
#define INFTY 1000000000/*修正 (10)⁹*/

int L[MAX/2+2],R[MAX/2+2];
int cnt;/*比較回数カウント*/

/*統治*/
void merge(int A[],int left,int mid,int right){
  int i;
  int n1 = mid - left;
  int n2 = right - mid;

  for(i = 0;i<n1;i++){/*n1を超えることはない*/
    L[i] = A[left + i];
  }
  for(i = 0;i<n2;i++){/*n2を超えることはない*/
    R[i] = A[mid + i];
  }
  /* L[n1] = INFTY
  R[n2] = INFTY*/
  L[n1] = R[n2] = INFTY;/*末尾へ*/
  i = 0;
  int j=0;
  for(int k = left;k<right;k++){/*for k = left to right-1*/
    cnt++;/*比較カウント*/
    if(L[i]<=R[j]){
      A[k] = L[i++];
      /*A[k] = L[i] ,i = i + 1*/
    }else{
      A[k] = R[j++];
      /*A[k] = R[j] ,j = j + 1*/
    }
  }
}

/*分割*/
void mergesort(int A[],int left,int right){
  if(left+1<right){/* if left+1 < right*/
    int mid = (left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}


int main(){
  int A[MAX],N,i;
   cnt = 0;

  scanf("%d",&N);/*10*/
  for(i = 0;i<N;i++){
    scanf("%d",&A[i]);/*8~4*/
  }

  mergesort(A,0,N);

  for(i = 0;i<N;i++){
    if(i != 0){
      printf(" ");
    }
      printf("%d",A[i]);
  }
    printf("\n");
       printf("%d\n",cnt);

  return 0;
}

