#include<stdio.h>

#define INFTY 1000000001
#define MAX 100000

typedef struct {
  char pic;
  int val;
}Card;

void mergeSort(Card*,int,int);
void merge(Card*,int,int,int);

int partition(Card* A,int p,int r){
  int x,i,j;
  Card temp;
  x=A[r].val;
  i=p-1;
  for(j=p;j<r;j++){
    if (A[j].val <= x){
      i = i+1;
      temp=A[i];
      A[i]=A[j];
      A[j]=temp;
    }
  }

  temp=A[i+1];
  A[i+1]=A[r];
  A[r]=temp;

  return i+1;
}

void quicksort(Card*A,int p,int r){
  int q;
  if(p<r){
    q=partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}


int main(){
  int n,i,flag=0,j;
  Card Q[MAX],M[MAX];
  char c[3];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s %d",c,&Q[i].val);
    M[i].pic=Q[i].pic=c[0];
    M[i].val=Q[i].val;
  }

  mergeSort(M,0,n);
  quicksort(Q,0,n-1);

  for(i=0;i<n;i++){
    if(Q[i].pic!=M[i].pic){
      flag=1;
      break;
    }
  }


  if(flag==0)
    printf("Stable\n");
  else
    printf("Not stable\n");

    for(i=0;i<n;i++){
      printf("%c %d\n",Q[i].pic,Q[i].val);
    }
  return 0;
}

void merge(Card*A, int left,int mid,int right){
  int n1,n2,k,i,j;

  n1 = mid - left;
  n2 = right - mid;

  Card L[n1+2],R[n2+2];

  for (i=0;i<n1;i++)
    L[i] = A[left + i];

  for (i=0;i<n2;i++)
    R[i] = A[mid + i];

  L[n1].val = INFTY;
  R[n2].val = INFTY;
  i = 0;
  j = 0;
  for (k=left;k<right;k++)
    if (L[i].val <= R[j].val){
      A[k] = L[i];
      i = i + 1;
    }
    else {
      A[k] = R[j];
      j = j + 1;
    }
}

void mergeSort(Card *A, int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

