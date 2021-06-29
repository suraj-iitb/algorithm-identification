#include<stdio.h>
#define MAX 100000
#define T 2000000000

typedef struct{
  char suit;
  int value;
}Card;

Card L[MAX/2+2],R[MAX/2+2];
void merge(Card A[], int n, int l, int m, int ri)
{
  int i, j, k;
  
  int a1, a2;
  a1=m-l;
  a2=ri-m;
  for(i=0;i<a1;i++)
    L[i]=A[l+i];
  for(i=0;i<a2;i++)
    R[i]=A[m+i];
  L[a1].value=R[a2].value=T;
  i=j=0;
  for(k=l;k<ri;k++){
    if(L[i].value<=R[j].value)
      A[k]=L[i++];
    else
      A[k]=R[j++];
  }
}

void qmerge(Card A[], int n, int l, int ri)
{
  int m;
  if(l+1<ri){
    m=(l+ri)/2;
    qmerge(A,n,l,m);

    
    qmerge(A,n,m,ri);
    
    merge(A,n,l,m,ri);
    
  }
}

int partition(Card A[], int n, int p, int r)
{
  int i, j;
  Card tmp, x;
  x=A[r];
  i=p-1;
  
  for(j=p;j<r;j++){
    if(A[j].value<=x.value){
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

void quick(Card A[], int a, int b, int c)
{
  int q=0;
  if(b<c){
    q=partition(A,a,b,c);
    
    quick(A,a,b,q-1);
    
    quick(A,a,q+1,c);
  }
}


int main(){
  int n, i, v;
  Card A[MAX],B[MAX];
  char S[11];
  int sta=1;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s %d",S,&v);
    A[i].suit=B[i].suit=S[0];
    A[i].value=B[i].value=v;
  }

  qmerge(A,n,0,n);
  quick(B,n,0,n-1);

  for(i=0;i<n;i++)
    if(A[i].suit!=B[i].suit)
      sta=0;

  if(sta==1)
    printf("Stable\n");
  else
    printf("Not stable\n");
  for(i=0;i<n;i++)
    printf("%c %d\n",B[i].suit,B[i].value);

  return 0;
}


