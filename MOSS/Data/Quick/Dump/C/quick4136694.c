#include<stdio.h>

#define INF 1000000001
#define MAX 100000

typedef struct{
  char suit;
  int num;
}Card;

int count;

void quickSort(Card *,int,int);
int Partition(Card *,int,int);
void merge(Card *,int,int,int);
void mergeSort(Card *,int,int);

int main(){
  int i,n,flag=0;
  Card A[MAX],B[MAX];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c %d",&A[i].suit,&A[i].num);
    B[i].suit=A[i].suit;
    B[i].num=A[i].num;
  }
  
  quickSort(A,0,n-1);
  mergeSort(B,0,n);

  for(i=0;i<n;i++){
    if(A[i].num==B[i].num && A[i].suit==B[i].suit);
    else{
      flag=1;
      break;
    }
  }

  if(flag==1) printf("Not stable\n");
  else printf("Stable\n");

  for(i=0;i<n;i++) printf("%c %d\n",A[i].suit,A[i].num);
  
  
  return 0;
  
}

void quickSort(Card *A,int p,int r){
  int q;

  if(p<r){
    q=Partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}

int Partition(Card *A,int p,int r){
  int i,j,x;
  Card tmp;

  x=A[r].num;
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].num<=x){
      i+=1;
      tmp=A[i];
      A[i]=A[j];
      A[j]=tmp;
    }
  }

  tmp=A[i+1];
  A[i+1]=A[r];
  A[r]=tmp;

  return i+1;
}

void merge(Card *A,int left,int mid,int right){
  int i,j,k,n1,n2;
  Card L[250001],R[250001];
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];

  L[n1].num=INF;
  R[n2].num=INF;
  
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i].num<=R[j].num){
      A[k]=L[i];
      i++;
      count++;
    }
    else{
      A[k]=R[j];
      j++;
      count++;
    }
  }
}

void mergeSort(Card *A,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

