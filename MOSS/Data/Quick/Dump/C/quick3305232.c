#include<stdio.h>
#include<string.h>
#define N 100000

typedef struct{
  int number;
  char symbol;
}Record;

void quicksort(Record *,int,int);
int partition(Record *,int,int);
void merge(Record *,int,int,int);
void mergesort(Record *,int,int);

int main(){
  int n,p,r,i,right,left=0,x=0,j;
  Record A[N],B[N];
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf(" %c%d", &(A[i].symbol), &(A[i].number));
  }

  for(i=0;i<n;i++){
    B[i].number = A[i].number;
    B[i].symbol = A[i].symbol;
  }

  r = n-1;
  right = n;
  p = 0;

  quicksort(A,p,r);

  mergesort(B,left,right);

  for(i=0;i<n;i++){
    if(!((A[i].number == B[i].number) && (A[i].symbol == B[i].symbol))){
	x = 1;
      }
  }
  if(x == 1){
    printf("Not stable\n");
  }else{
    printf("Stable\n");
    }

  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].symbol,A[i].number);
    }

  return 0;
}




void quicksort(Record A[],int p,int r){
  int q;
  if(p < r){
    q = partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}

int partition(Record A[],int p,int r){
  int i,j,x;
  x = A[r].number;
  Record temp,temp2;
  i = p - 1;
  for(j=p;j<r;j++){
    if(A[j].number <= x){
      i++;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  temp2 = A[i+1];
  A[i+1] = A[r];
  A[r] = temp2;
  
  return i+1;
}

void merge(Record B[],int left,int mid,int right){
  int n1,n2,i,j,k;
  Record L[N],R[N];
  n1 = mid - left;
  n2 = right - mid;

  for(i=0;i<n1;i++){
    L[i] = B[left + i];
  }

  for(i=0;i<n2;i++){
    R[i] = B[mid + i];
  }

  L[n1].symbol = 'X';
  L[n1].number = 1000000000;
  R[n2].symbol = 'X';
  R[n2].number = 1000000000;
  i = 0;
  j = 0;

  for(k=left;k<right;k++){
    if(L[i].number <= R[j].number){
      B[k] = L[i];
      i++;
    }else{
      B[k] = R[j];
      j++;
    }
  }
}

void mergesort(Record B[],int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergesort(B,left,mid);
    mergesort(B,mid,right);
    merge(B,left,mid,right);
  }
}

