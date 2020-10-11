//Quick Sort

#include<stdio.h>
#include<stdlib.h>

#define SENTINEL 1000000001

typedef struct{
  int num;
  char suit;
}Data;


void Quicksort(Data*,int,int);

int Partition(Data*,int,int);

void Swap(Data*,Data*);

void Merge_sort(Data*,int,int);

void Merge(Data*,int,int,int);

int Test_stable(Data,Data);


int main(void){
  int n;
  Data *data,*stable_data;
  int i;
  char garbage;

  scanf("%d",&n);

  //%cは改行やスペースを読み込むのでその対策
  scanf("%c",&garbage);

  data=(Data*)malloc(n*sizeof(Data));
  stable_data=(Data*)malloc(n*sizeof(Data));

  for(i=0;i<n;i++){
    scanf("%c %d",&data[i].suit,&data[i].num);
    scanf("%c",&garbage);
    stable_data[i]=data[i];
  }

  Quicksort(data,0,n-1);

  Merge_sort(stable_data,0,n);

  for(i=0;i<n;i++){
    if(data[i].suit!=stable_data[i].suit){
      printf("Not stable\n");
      break;
    }
  }
  if(i==n) printf("Stable\n");

  for(i=0;i<n;i++) printf("%c %d\n",data[i].suit,data[i].num);


  free(data);
  free(stable_data);

  return 0;
}

void Quicksort(Data *A,int p,int r){
  int work;

  if(p<r){
    work=Partition(A,p,r);
    Quicksort(A,p,work-1);
    Quicksort(A,work+1,r);
  }
}

int Partition(Data *A,int p,int r){
  int pivot;
  int i,j;

  pivot=A[r].num;

  j=p;
  for(i=p;i<r;i++){
    if(A[i].num<=pivot){
      Swap(&A[i],&A[j]);
      j++;
    }
  }
  Swap(&A[j],&A[r]);

  return j;
}

void Swap(Data *a,Data *b){
  Data work;

  work=*a;
  *a=*b;
  *b=work;
}

void Merge_sort(Data *A,int left,int right){
  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    Merge_sort(A,left,mid);
    Merge_sort(A,mid,right);
    Merge(A,left,mid,right);
  }
}

void Merge(Data *A,int left,int mid,int right){
  int n1,n2;
  Data *L,*R;
  int i,j,k;

  n1=mid-left;
  n2=right-mid;

  L=(Data*)malloc(sizeof(Data)*(n1+1));
  R=(Data*)malloc(sizeof(Data)*(n2+1));

  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];

  L[n1].num=SENTINEL;
  L[n1].suit=' ';
  R[n2].num=SENTINEL;
  R[n2].suit=' ';

  i=0;
  j=0;

  for(k=left;k<right;k++){
    if(L[i].num<=R[j].num){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
  }

  free(L);
  free(R);
}
