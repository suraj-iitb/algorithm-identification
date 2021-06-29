#include<stdio.h>
#define MAX 100000
#define S 2000000000

struct C {
  char a;
  int b;
};

struct C L[MAX/2+2],R[MAX/2+2];

void merge(struct C A[],int n, int left,int mid,int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int i,j=0,k;
  // L[0...n1], R[0...n2] を生成                                                
  for(i = 0 ;i<n1;i++)L[i] = A[left + i];
  for (i = 0;i<n2;i++)R[i] = A[mid + i];

  L[n1].b = S;
  R[n2].b = S;
  i=0;
  for(k = left;k<right;k++){
      if(L[i].b <= R[j].b){
      A[k] = L[i++];

    }
    else {
      A[k] = R[j++];

    }
  }
}

void mergeSort(struct C A[],int n,int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);

  }
}
int partition(struct C A[],int n,int p,int r){
  int i,j;
  struct C x,tmp;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].b<=x.b){
      i++;
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
void quicksort(struct C A[],int n,int p,int r){
  int q;
  if(p<r){
    q=partition(A,n,p,r);
    quicksort(A,n,p,q-1);
    quicksort(A,n,q+1,r);
  }
}
int main(){
  int n,i,suu,sta=1;
  struct C A[MAX],B[MAX];
  char C[10];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %d",C,&suu);
    A[i].a=B[i].a=C[0];
    A[i].b=B[i].b=suu;
  }

  mergeSort(A,n,0,n);
  quicksort(B,n,0,n-1);

  for(i=0;i<n;i++){
    if(A[i].a!=B[i].a)sta=0;
  }
  if(sta==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",B[i].a, B[i].b);
  }


  return 0;
}

