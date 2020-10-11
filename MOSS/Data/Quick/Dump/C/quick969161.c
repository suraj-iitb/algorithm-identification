#include <stdio.h>

typedef struct {
  char s;
  int num;
} card;


card A[100001];
card B[100001];
int n;
int par(card[],int,int);
void qsort(card [],int ,int);
void merge(card[],int,int,int);
void mergesort(card[],int,int);
void checkstable();
int judge(card,card);

int main(){
  int i;
  char ch;
  scanf("%d",&n);
  scanf("%c",&ch);

  for(i=1;i<=n;i++){
    scanf("%c",&A[i].s);
    scanf("%d",&A[i].num);
    scanf("%c",&ch);
    B[i]=A[i];
  }

  qsort(A,1,n);

  checkstable();
  for(i=1;i<=n;i++){
    printf("%c",A[i].s);
    printf(" %d\n",A[i].num);
    
  }

  return 0;
}

int par(card A[],int p,int r){
  int i,j;
  card x=A[r],s;
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].num<=x.num){
      i =i+1;
      s=A[i];
      A[i]=A[j];
      A[j]=s;
    }
  }
  s=A[i+1];
  A[i+1]=A[r];
  A[r]=s;
  return i+1;
}


void qsort(card A[],int p,int r){
  int q;
  if(p<r){
    q = par(A,p,r);
    qsort(A,p,q-1);
    qsort(A,q+1,r);
  }
}

void checkstable(){
  mergesort(B,1,n+1);
  int i;
  for(i=1;i<=n;i++){
    if( judge(A[i],B[i]) == 0){
      printf("Not stable\n");
      return;
    }
  }
  printf("Stable\n");
}

void merge(card S[],int l,int m,int r){
  int i,j,k;
  int n1,n2;
  card L[500000];
  card R[500000];
  n1=m-l;
  n2=r-m;
  for(i=0;i<n1;i++){
    L[i]=S[l+i];
  }
  for(i=0;i<n2;i++){
    R[i]=S[m+i];
  }
  L[n1].num=1000000001;
  R[n2].num=1000000001;
  i = 0;
  j = 0;
  for(k=l;k<r;k++){
    if(L[i].num<=R[j].num){
      S[k]=L[i];
      i = i+1;
    } else{
      S[k]=R[j];
      j = j+1;
    }
  }
}
 
void mergesort(card S[],int l,int r){
  int m;
  if(l+1 < r){
    m = (l+r)/2;
    mergesort(S,l,m);
    mergesort(S,m,r);
    merge(S,l,m,r);
  }
}

int judge(card a,card b){
  if(a.s!=b.s){
    return 0;
  } else if(a.num!=b.num){
    return 0;
  } else {
    return 1;
  }
}
