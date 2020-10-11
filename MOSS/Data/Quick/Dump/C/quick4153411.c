#include <stdio.h>
#include <stdlib.h>
#define INF 100000000

typedef struct{
  int num;
  char c;
}Card;

Card A[100000],B[100000];
  int n;

int partition(int p, int r);

void merge(Card *, int, int, int);
void mergeSort(Card *, int, int);

void quicksort(int p, int r){
  int q,i;
  //  for(i=0;i<n;i++)printf("%d ",A[i].num);printf("\n");
  if(p<r)
    {
      q = partition(p,r);
      quicksort(p, q-1);
      quicksort(q+1, r);

    }
  
}


int table(void){

  int i;

  for(i=0;i<n;i++){
    if(A[i].c!=B[i].c)return 0;

  }

  return 1;
}


int main(){
  int i;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf(" %c%d",&A[i].c,&A[i].num);
    B[i].c = A[i].c;
    B[i].num = A[i].num;
  }

  quicksort(0,n-1);
  mergeSort(B, 0, n);

  if(table())printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].c,A[i].num);
  }
  
  return 0;
}
int partition(int p, int r){
  int i,j;
  Card x,tmp;

  x = A[r];
  i = p-1;
  for(j=p;j<r;j++){
    if(A[j].num <= x.num){
      i++;
      tmp = A[j];
      A[j] = A[i];
      A[i] = tmp;
    }
  }
  tmp = A[r];
  A[r] = A[i+1];
  A[i+1] = tmp;
  return i+1;

}

void mergeSort(Card *A, int left, int right){

  int mid;
  
  if(left+1 < right){
    mid = (left+right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);


  }


}

void merge(Card *A, int left, int mid, int right){

  int i,j,k,n1,n2;
  Card l[500000],r[500000];
  
  n1 = mid - left;
  n2 = right - mid;
  
  // l = malloc(sizeof(int)*n1);
  // r = malloc(sizeof(int)*n2);

  for(i=0;i<n1;i++)l[i]=A[left+i];
  for(i=0;i<n2;i++)r[i]=A[mid+i];
  l[n1].num=INF;r[n2].num=INF;
  i=0;j=0;

  for(k=left;k<right;k++){
    if(l[i].num<=r[j].num){
      A[k]=l[i];
      i++;
    }
    else{
      A[k]=r[j];
      j++;
    }

  }
  
}

