#include<stdio.h>
#define MAX 100000
#define INF 1000000000
 
typedef struct card{
  char s;
  int v;
}Card;

void M(Card A[],int l,int m,int r);
void Ms(Card A[],int l,int r);
int P(Card A[],int p,int r);
void Qs(Card A[],int p,int r);
 
 
int main(){
  int i,j,n,v,stable = 0;
  Card A[MAX],B[MAX];
  char s;
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c%d",&s,&v);
    A[i].s = B[i].s = s;
    A[i].v = B[i].v = v;
  }
 
  Ms(A,0,n);
  Qs(B,0,n-1);
 
  for(i=0;i<n;i++){
    if(A[i].s != B[i].s) stable = 1;
  }
 
  if(stable == 0)printf("Stable\n");
  else printf("Not stable\n");
 
  for(i=0;i<n;i++){
    printf("%c %d\n",B[i].s,B[i].v);
  }
  return 0;
}


void M(Card A[],int l,int m,int r){
  Card R[MAX/2+2],L[MAX/2+2];
  int i,j,k;
  int n1,n2;
  n1 = m - l;
  n2 = r - m;
 
  for(i=0;i<n1;i++){
    L[i] = A[l+i];
  }
  for(i=0;i<n2;i++){
    R[i] = A[m+i];
  }
  L[n1].v = INF;
  R[n2].v = INF;
  i = 0;
  j = 0;
 
  for(k=l;k<r;k++){
    if(L[i].v <= R[j].v){
      A[k] = L[i++];
    }else{
      A[k] = R[j++];
    }
  }
}



void Ms(Card A[],int l,int r){
  int m;
  if(l + 1 < r){
    m = (l+r)/2;
    Ms(A,l,m);
    Ms(A,m,r);
    M(A,l,m,r);
  }
}


int P(Card A[],int p,int r){
  Card tmp,x;
  int i,j;
 
  x = A[r];
  i = p - 1;
  for(j=p;j<r;j++){
    if(A[j].v <= x.v){
      i++;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;
 
  return i + 1;
}

void Qs(Card A[],int p,int r){
  int q;
  if(p<r){
    q = P(A,p,r);
    Qs(A,p,q-1);
    Qs(A,q+1,r);
  }
}

