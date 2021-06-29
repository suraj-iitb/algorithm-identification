#include<stdio.h>
#define MAX 100000
#define SEN 2000000000

struct card{
  char suit;
  int value;
};
struct card R[MAX/2+2],L[MAX/2+2];

void merge(struct card *,int,int,int,int);
void mergesort(struct card *,int,int,int);
int partition(struct card *,int,int,int);
void quicksort(struct card *,int,int,int);

int main(){
  int n,i,s,stable;
  struct card A[MAX],B[MAX];
  char C[10];
  stable = 1;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %d",C,&s);
    A[i].suit=B[i].suit=C[0];
    A[i].value=B[i].value=s;
  }
  mergesort(A,n,0,n);
  quicksort(B,n,0,n-1);
  for(i=0;i<n;i++){
    if(A[i].suit != B[i].suit){
      stable  = 0;
    }
    }
  if(stable == 1){
      printf("Stable\n");
    }
    else printf("Not stable\n");
    for(i=0;i<n;i++){
      printf("%c %d\n",B[i].suit,B[i].value);
    }
    return 0;
}
void merge(struct card A[],int n,int l,int m,int r){
  int k,i,j,n1,n2;
  n1=m-l;
  n2=r-m;
  for(i=0;i<n1;i++){
    L[i]=A[l+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[m+i];
  }
  L[n1].value=R[n2].value=SEN;
  i=0;
  j=0;
  for(k=l;k<r;k++){
    if(L[i].value <= R[j].value)A[k]=L[i++];
    else A[k] = R[j++];
  }
}
void mergesort(struct card A[],int n,int l,int r){
  int m1;
  if(l+1 < r){
    m1=(l+r)/2;
  mergesort(A,n,l,m1);
    mergesort(A,n,m1,r);
    merge(A,n,l,m1,r);
  }
}
int partition(struct card A[],int a,int b,int c){
  int i,j;
  struct card x,y;
  x=A[c];
  i=b-1;
  for(j=b;j<c;j++){
    if(A[j].value <= x.value){
      i++;
      y=A[i];
      A[i]=A[j];
      A[j]=y;
    }
  }
  y=A[i+1];
  A[i+1]=A[c];
  A[c]=y;
  return i+1;
}
void quicksort(struct card A[],int n,int p,int r){
  int w;
  if(p < r){
    w = partition(A,n,p,r);
    quicksort(A,n,p,w-1);
    quicksort(A,n,w+1,r);
  }
}
