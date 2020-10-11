#include <stdio.h>
#define MAX 100000

struct T{
  char mark;
  int num;
};


  
int p(struct T A[],int a,int b);
void q(struct T A[],int a,int b);
void merge(struct T  A[],int l,int m,int r);
void mergesort(struct T A[],int l,int r);

int n;
struct T L[MAX/2+2],R[MAX/2+2];

int main(){
  int i,m,st=1;
  struct T X[MAX],Y[MAX];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    getchar();
    scanf("%c %d",&X[i].mark,&X[i].num);
    Y[i]=X[i];
  }
  
  mergesort(X,0,n);
  
  q(Y,0,n-1);

  for(i=0;i<n;i++){
    if(X[i].mark!=Y[i].mark) st=0;
  }
  if(st==1) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++)printf("%c %d\n",Y[i].mark,Y[i].num);
  
  return 0;
}

int p(struct T A[],int a,int b){
  int i,j;
  struct T x,t;
  x=A[b];
  i=a-1;
  for(j=a;j<b;j++){
    if(A[j].num<=x.num){
      i=i+1;
      t=A[i];
      A[i]=A[j];
      A[j]=t;
    }
  }
  t=A[i+1];
  A[i+1]=A[b];
  A[b]=t;
   return i+1;
}

void q(struct T A[],int a,int b){
  int m;
  if(a<b){
    m=p(A,a,b);
    q(A,a,m-1);
    q(A,m+1,b);
  }
}

void merge(struct T A[],int l,int m,int r){
  int n1,n2,i,j,k;
  n1=m-l;
  n2=r-m;
  for(i=0;i<n1;i++) L[i]=A[l+i];
  for(i=0;i<n2;i++) R[i]=A[m+i];
  L[n1].num=R[n2].num=2000000000;
  i=0,j=0;
  for(k=l;k<r;k++){
    if(L[i].num<=R[j].num){
      A[k]=L[i];
      i++;
    }else{
      A[k]=R[j];
      j++;
    }
  }
}
void mergesort(struct T A[],int l,int r){
  if(l+1<r){
    int m;
    m=(l+r)/2;
    mergesort(A,l,m);
    mergesort(A,m,r);
    merge(A,l,m,r);
  }
}

  

