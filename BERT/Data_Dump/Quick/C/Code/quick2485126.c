#include <stdio.h>
#include <stdbool.h>

#define MAX 100000
#define SEN 10000000

typedef struct {
    char gara;
    int value;
}Huda;

void merge(Huda[],int,int,int);
void mergeSort(Huda[],int,int);
int partition(Huda[],int,int);
void swap(Huda*,Huda*);
void quickSort(Huda[],int,int,int);
void printArray(Huda [],int);
bool isStable(Huda [],Huda[],int N);



Huda L[MAX],R[MAX];

int main(){
  int n;
  int i;
  Huda H1[MAX],H2[MAX];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&H1[i].gara,&H1[i].value);
    H2[i].gara=H1[i].gara;
    H2[i].value=H1[i].value;
  }

mergeSort(H1,0,n);
quickSort(H2,n,0,n-1);


if(isStable(H1,H2,n)){
  printf("Stable\n");
}else printf("Not stable\n");
 printArray(H2,n);


return 0;
}


void  merge(Huda A[],int left,int mid,int right){
  int i,j=0,k=0;
  int nm1=mid-left;
  int nm2=right-mid;
  for(i=0;i<nm1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<nm2;i++){
    R[i]=A[mid+i];
  }
  L[nm1].value=SEN;
  R[nm2].value=SEN;
  i=0;
  for(k=left;k<right;k++){
    if(L[i].value<=R[j].value){
      A[k]=L[i++];
    }else{
      A[k]=R[j++];
    }
  }
}

void mergeSort(Huda A[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int partition(Huda A[],int p,int r){
  Huda x;
  int i,j;
  
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].value<=x.value){
      i++;
      swap(&A[i],&A[j]);
    }
  }
  swap(&A[i+1],&A[r]);
  return i+1;
}

void swap(Huda *a,Huda *b){
  Huda  v;
  v=*a;
  *a=*b;
  *b=v;
}

void quickSort(Huda A[],int n,int p,int r){
  int q;
  if(p<r){
    q=partition(A,p,r);
    quickSort(A,n,p,q-1);
    quickSort(A,n,q+1,r);
  }
}


bool isStable(Huda H1[],Huda H2[],int N){
  int i;
  for(i=0;i<N;i++){
    if(H1[i].gara!=H2[i].gara)return false;
  }
return true;
}

void printArray(Huda A[],int N){
  int i;
  for(i=0;i<N;i++){
    printf("%c %d\n",A[i].gara,A[i].value);
  }
}
