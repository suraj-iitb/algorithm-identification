#include <stdio.h>
#define N 100000
#define M 2000000000

typedef struct Card{
  char m;
  int n;
} Card;

void merge(Card *,int ,int ,int ,int);
void merges(Card *,int ,int ,int);
int part(Card *,int ,int ,int);
void quicks(Card *,int ,int ,int);

Card L[N/2+2] ,R[N/2+2];

int main() {
  int n ,i ,v ,m=1;
  Card a[N] ,b[N];
  char s[10];

  scanf("%d" ,&n);

  for(i=0;i<n;i++){
    scanf("%s %d" ,s ,&v);
    a[i].m=b[i].m=s[0];
    a[i].n=b[i].n=v;
  }
  merges(a ,n ,0 ,n);
  quicks(b ,n ,0 ,n-1);

  for(i=0;i<n;i++){
    if(a[i].m!=b[i].m) m=0;
  }

  if(m==1)printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++){
    printf("%c %d\n" ,b[i].m ,b[i].n);
  }

  return 0;
}

void merge(Card a[],int n,int l,int m,int r){
  int i ,j ,k ,n1=m-l ,n2=r-m;
  for(i=0;i<n1;i++){
    L[i]=a[l+i];
  }
  for(i=0;i<n2;i++){
    R[i]=a[m+i];
  }

  L[n1].n=R[n2].n=M;
  i=j=0;
  for(k=l;k<r;k++){
    if(L[i].n<=R[j].n) a[k]=L[i++];
    else a[k]=R[j++];
  }
}

void merges(Card a[] ,int n ,int l ,int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    merges(a ,n ,l ,m);
    merges(a ,n ,m ,r);
    merge(a ,n ,l ,m ,r);
  }
}

int part(Card a[] ,int n ,int p ,int r){
  int i ,j;
  Card t ,x;
  x=a[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(a[j].n<=x.n){
      i++;
      t=a[i];
      a[i]=a[j];
      a[j]=t;
    }
  }
  t=a[i+1];
  a[i+1]=a[r];
  a[r]=t;

  return i+1;
}

void quicks(Card a[],int n ,int p ,int r){
  int q;
  if(p<r){
    q=part(a ,n ,p ,r);
    quicks(a ,n ,p ,q-1);
    quicks(a ,n ,q+1 ,r);
  }
}
