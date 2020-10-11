#include <stdio.h>

#define NMAX 100001
#define SENT 1000000002

struct Card{
  char suit;
  int num;
};

struct Card L[2 + NMAX/2],R[2 + NMAX/2];

void merge(struct Card A[],int n,int left,int mid,int right){
  int i,j,k;
  int n1 = mid - left,n2 = right - mid;

  for(i = 0;i < n1;i++){
    L[i] = A[left + i];
  }
  for(i = 0;i < n2;i++){
    R[i] = A[mid + i];
  }

  L[n1].num = R[n2].num = SENT;
  i = j = 0;
  for(k = left;k < right;k++){
    if(L[i].num <= R[j].num){
      A[k] = L[i++];
    }else{
      A[k] = R[j++];
    }
  }
}

void mergeSort(struct Card A[],int n,int left,int right){
  int mid;

  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}

int partition(struct Card A[],int n,int p,int r){

  int i,j;
  struct Card temp,x;

  x = A[r];
  i = p - 1;
  for(j = p;j < r;j++){
    if(A[j].num <= x.num){
      i++;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  temp = A[i + 1];
  A[i + 1] = A[r];
  A[r] = temp;

  return i + 1;
}

void quickSort(struct Card A[],int n,int p,int r){

  int q;
  if(p < r){
    q = partition(A,n,p,r);
    quickSort(A,n,p,q - 1);
    quickSort(A,n,q + 1,r);
  }
}

int main(void){

  int i,n,v,stable = 1;
  struct Card A[NMAX],B[NMAX];
  char S[10];

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%s %d",S,&v);
    A[i].suit = B[i].suit = S[0];
    A[i].num = B[i].num = v;
  }

  mergeSort(A,n,0,n);
  quickSort(B,n,0,n - 1);

  for(i = 0;i < n;i++){
    if(A[i].suit != B[i].suit){
    stable = 0;
    }
  }

  if(stable == 1){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }
  for(i = 0;i < n;i++){
      printf("%c %d\n",B[i].suit,B[i].num);
  }

  return 0;
}
  

  

