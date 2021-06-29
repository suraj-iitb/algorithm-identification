#include<stdio.h>

#define N 100000

typedef struct pp{
  char name;
  int value;
}CARD;

CARD data[N],data1[N];

void quicksort(CARD*,int,int);
int partition(CARD*,int,int);
int isstable(CARD*,CARD*,int);
/*void BubbleSort(CARD*,int);*/
void merge(CARD*,int,int,int);
void mergeSort(CARD*,int,int);

int main(){
  int i,j,a,b,n;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c",&data[i].name);
    scanf("%d",&data[i].value);

    data1[i]=data[i];
  }

  quicksort(data,0,n-1);

  /*BubbleSort(data1,n);*/

  mergeSort(data1,0,n);
  
  a=isstable(data1,data,n);

  if(a==1) printf("Stable\n");
  else printf("Not stable\n");

  
  
  for(i=0;i<n;i++){
    printf("%c %d\n",data[i].name,data[i].value);
  }
  return 0;
}

void quicksort(CARD *A,int p,int r){
  int q;
  
  if(p<r){
    q=partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
  return;
}

int partition(CARD *A,int p,int r){
  int i,j;
  CARD temp,x;

  x=A[r];
  i=p-1;

  for(j=p;j<r;j++){
    if(A[j].value<=x.value){
      i++;
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

int isstable(CARD *in,CARD *out,int n){
  int i,j,a=0,b=0;
  
  for(i=0;i<n;i++){
    if(in[i].name==out[i].name) a++;
    if(in[i].value==out[i].value) b++;
  }
  
  

  if(a==b) return 1;

  else return 0;
  
  }

/*void BubbleSort(CARD *B,int n){
    int i,j;
  CARD temp;
  
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(B[j].value<B[j-1].value){
	temp=B[j];
	B[j]=B[j-1];
	B[j-1]=temp;
      }
    }
  }

  return;
  }*/

void merge(CARD *A,int left,int mid,int right){
  int n1,n2,i,k,j;
  n1=mid-left;
  n2=right-mid;
  CARD L[n1],R[n2];

  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }

  L[n1].value=2147483647;
  R[n2].value=2147483647;

  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i].value<=R[j].value){
      A[k]=L[i];
      i=i+1;
    }
    else{
      A[k]=R[j];
      j=j+1;
    }
  }

  return;
}
  
void mergeSort(CARD *A,int left,int right){
  int mid;
  
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }

  return;
}

