#include<stdio.h>
#define MAX 100000
#define S 1000000000
typedef struct{
  char pic;
  int num;
}CARD;

int n;

void merge(CARD *,int, int, int);
void mergeSort(CARD *,int ,int);
int partition(CARD *,int, int);
void quickSort(CARD *,int,int);

int main(){
  int i,judge=1;/*judgeが1だったらStable、0だったらNot stable*/
  char a[5];
  CARD merge[MAX],quick[MAX];
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s %d",a,&merge[i].num);
    quick[i].pic=merge[i].pic=a[0];
    quick[i].num=merge[i].num;
  }

  mergeSort(merge,0,n);
  quickSort(quick,0,n-1);

  for(i=0;i<n;i++){
    if(merge[i].pic!=quick[i].pic){
      judge=0;
    }
  }

  if(judge==1){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

  for(i=0;i<n;i++){
    printf("%c %d\n",quick[i].pic,quick[i].num);
  }
  
  return 0;
}

void merge(CARD *A,int left,int mid,int right){
  int n1,n2,i,j,k;
  CARD L[MAX],R[MAX];
  n1 = mid - left;
  n2 = right - mid;
  for(i=0;i<=n1-1;i++){
    L[i]=A[left+i];
  }

  for(i=0;i<=n2-1;i++){
    R[i]=A[mid+i];
  }
  
  L[n1].num=S;
  R[n2].num=S;
  i=0;
  j=0;

  for(k=left;k<=right-1;k++){
    if(L[i].num<=R[j].num){
      A[k]=L[i];
      i=i+1;
    }else{
      A[k]=R[j];
      j=j+1;
    }
  }
}

void mergeSort(CARD *A,int left,int right){
  int mid;  
  if(left+1<right){
    mid = (left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}



int partition(CARD *A,int p,int r){
  int i,j;
  CARD x,s;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].num<=x.num){
      i=i+1;
      s=A[j];
      A[j]=A[i];
      A[i]=s;
    }
  }
  s=A[r];
  A[r]=A[i+1];
  A[i+1]=s;
  return i+1;
}


void quickSort(CARD *A,int p,int r){
  int q;
  if(p<r){
    q=partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}

