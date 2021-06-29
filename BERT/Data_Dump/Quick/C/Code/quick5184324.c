#include<stdio.h>
#define MAX 100000
#define INFTY 1000000000

struct card{
  char moji;
  int kazu;
};


struct card L[MAX/2+2],R[MAX/2+2];
int cnt;/*比較回数カウント*/

/*統治*/
void merge(struct card A[],int left,int mid,int right){
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
  L[n1].kazu = R[n2].kazu = INFTY;/*末尾へ*/
  i = 0;
  int j=0;
  for(int k = left;k<right;k++){/*for k = left to right-1*/
    cnt++;/*比較カウント*/
    if(L[i].kazu<=R[j].kazu){
      A[k] = L[i++];
      /*A[k] = L[i] ,i = i + 1*/
    }else{
      A[k] = R[j++];
      /*A[k] = R[j] ,j = j + 1*/
    }
  }
}

/*分割*/
void mergesort(struct card A[],int left,int right){
  if(left+1<right){/* if left+1 < right*/
    int mid = (left+right)/2;
       mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int partition(struct card A[],int p, int r){
  int i,j;
  struct card tmp,x;
  x = A[r];
    i = p-1;

    for (j = p;j< r;j++){

      if( A[j].kazu <= x.kazu){
        i = i+1;
        tmp = A[i];/*A[i] と A[j] を交換*/
        A[i] = A[j];
               A[j] = tmp;
      }
    }
    tmp = A[i+1];/*A[i+1] と A[r] を交換*/
    A[i+1] = A[r];
    A[r] = tmp;

    return i+1;
  }
/*
1 quicksort(A, p, r)
2   if p < r
3     q = partition(A, p, r)
4     quickSort(A, p, q-1)
5     quickSort(A, q+1, r)
*/
void quicksort(struct card A[],int p,int r){
  int q;
    if(p<r){
    q = partition(A,p,r);/*作る対象*/
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}

int main(){
  int n,i,v;
  struct card A[MAX],B[MAX];
  char S[10];
  int stable = 1;

  scanf("%d",&n);/*6*/

  for(i = 0;i<n;i++){
    scanf("%s %d",S,&v);/*D 3*/
    A[i].moji = B[i].moji = S[0];
    A[i].kazu = B[i].kazu = v;

  }
  
   mergesort(A,0,n);
  quicksort(B,0,n-1);

  for(i = 0;i<n;i++){/*マージとクイックの安定性を比較する*/
    if(A[i].moji != B[i].moji){
      stable = 0;
    }
  }
    if(stable == 1){
      printf("Stable\n");
    }else {
      printf("Not stable\n");
    }
    for(i = 0;i<n;i++){
      printf("%c %d\n",B[i].moji,B[i].kazu);
    }
    return 0;
  }




