#include<stdio.h>
#define MAX 100005
#define INFTY 1000000000
typedef struct{
  char c;
  int  n;
} Card;

void Merge(Card *A,int left,int mid,int right){
  int n1,n2,i,j,k;
  Card l[MAX/2],r[MAX/2];

  n1 = mid-left;
  n2 = right-mid;
  for(i=0;i<n1;i++) l[i] = A[left+i];
  for(i=0;i<n2;i++) r[i] = A[mid+i];
  l[n1].n = INFTY;
  r[n2].n = INFTY;
  i=0;
  j=0;

  for(k=left;k<right;k++){
    if(l[i].n<=r[j].n){
      A[k] = l[i];
      i++;
    }
    else{
      A[k] = r[j];
      j++;
    }
  }
}

void MergeSort(Card *A, int left, int right){
  int mid;

  if(left+1<right){
    mid = (left+right)/2;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    Merge(A, left, mid, right);
  }
}

int Partition(Card *A,int p,int r){
  int x,i,j;
  Card tmp;

  x = A[r].n;
  i = p-1;
  for(j=p;j<r;j++){
    if(A[j].n<=x){
      i++;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
 tmp = A[i+1];
 A[i+1] = A[r];
 A[r] = tmp;

  return i+1;
}

void QuickSort(Card *A, int p, int r){
  int q;

  if(p<r){
    q = Partition(A,p,r);
    QuickSort(A,p,q-1);
    QuickSort(A,q+1,r);
  }
}

int main(){
  Card A[MAX],B[MAX];
  int n,i,left,right,flag=0;

  scanf("%d",&n);
  left = 0;
  right = n;
  for(i=0;i<n;i++){
    scanf("%s %d",&A[i].c,&A[i].n);
    B[i] = A[i];
  };
  QuickSort(A,0,n-1);
  MergeSort(B,left,right);
  for(i=0;i<n;i++){
    if(A[i].c != B[i].c){
      flag++;
      printf("Not stable\n");
      break;
    }
  }
  if(flag == 0) printf("Stable\n");

  for(i=0;i<n;i++) printf("%c %d\n",A[i].c,A[i].n);

  return 0;
}

