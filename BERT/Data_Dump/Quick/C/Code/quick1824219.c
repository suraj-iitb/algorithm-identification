#include<stdio.h>
#define MAX 1000001
#define INF 20000000

typedef struct{
  int A;
  char C;
}Card;


Card A[MAX];
Card B[MAX];

Card L[MAX/2+2],R[MAX/2+2];

void quickSort(int,int);
int partition(int,int);

void merge(int,int,int,int);
void mergeSort(int,int,int);

int main(){
  int i;
  int n;
  int c;
  int flag=1;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%c",&c);
    scanf("%c%d",&A[i].C,&A[i].A);
    B[i].A=A[i].A;
    B[i].C=A[i].C;
  }

  quickSort(0,n-1);
  mergeSort(n,0,n);
  
  for(i=0;i<n;i++){
    if(B[i].A==A[i].A&&B[i].C!=A[i].C){
      flag=0;
      break;
    }
  }

  if(flag==1)printf("Stable\n");
  else if(flag==0)printf("Not stable\n");

  for(i=0;i<n;i++)printf("%c %d\n",A[i].C,A[i].A);
  return 0;
}

int partition(int p,int r){
  int i,j;
  int x;
  Card t;

  x=A[r].A;
  i=p-1;
  
  for(j=p;j<r;j++){
    if(x>=A[j].A){
      t=A[j];
      A[j]=A[i+1];
      A[i+1]=t;
      i++;
    }
  }
  t=A[i+1];
  A[i+1]=A[r];
  A[r]=t;
 
  return i+1;
}

void quickSort(int p,int r){
  int q;
  
  if(p<r){
    q=partition(p,r);
    quickSort(p,q-1);
    quickSort(q+1,r);
  }
}

void merge(int n,int left,int mid,int right){
  int i,j,k;
  int n1;
  int n2;

  n1=mid-left;
  n2=right-mid;

  for(i=0;i<n1;i++) L[i]=B[left+i];
  for(i=0;i<n2;i++) R[i]=B[mid+i];

  L[n1].A=INF;
  R[n2].A=INF;

  i=0;
  j=0;

  for(k=left;k<right;k++){
    if(L[i].A<=R[j].A){
      B[k]=L[i];
      i++;
    }else{
      B[k]=R[j];
      j++;
    }
  }
}

void mergeSort(int n,int left,int right){
  int mid;

  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(n,left,mid);
    mergeSort(n,mid,right);
    merge(n,left,mid,right);
  }
}
