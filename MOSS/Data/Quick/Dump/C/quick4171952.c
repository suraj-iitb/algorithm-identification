#include <stdio.h>

#define M 100000
#define SEN 2000000000

struct Card {
  char suit;
  int value;
};
struct Card L[M/2+2],R[M/2+2];

void merge(struct Card*,int,int,int,int);
void mergesort(struct Card*,int,int,int);
int partition(struct Card*,int,int,int);
void quicksort(struct Card*,int,int,int);

int main(){

  int n,i,v;
  struct Card S[M],T[M];
  char C[10];
  int stable = 1;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s %d",C,&v);
    S[i].suit=T[i].suit=C[0];
    S[i].value=T[i].value=v;
  }
  mergesort(S,n,0,n);
  quicksort(T,n,0,n-1);


  for(i=0;i<n;i++)
    if(S[i].suit!=T[i].suit)stable=0;

  if(stable==1)
    printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++)
    printf("%c %d\n",T[i].suit,T[i].value);

return 0;
}
void merge(struct Card* S,int n,int l,int m,int r){
  int i,j,k,n1,n2;
  n1=m-l;
  n2=r-m;
  for(i=0;i<n1;i++)
    L[i]=S[l+i];
  for(i=0;i<n2;i++)
    R[i]=S[m+i];
  L[n1].value=R[n2].value=SEN;
  i=j=0;
  for(k=l;k<r;k++){
    if(L[i].value<=R[j].value){
      S[k]=L[i++];
    }
    else S[k]=R[j++];
  }
}
void mergesort(struct Card*S,int n,int l,int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    mergesort(S,n,l,m);
    mergesort(S,n,m,r);
    merge(S,n,l,m,r);
  }
}
int partition(struct Card* S,int n,int p,int r){
  int i,j;
  struct Card t,x;
  x=S[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(S[j].value<=x.value){
      i++;
      t=S[i];
      S[i]=S[j];
      S[j]=t;
    }
  }
  t=S[i+1];
  S[i+1]=S[r];
  S[r]=t;
  return i+1;
}
void quicksort(struct Card* S,int n,int p,int r){
  int q;
  if(p<r){
    q=partition(S,n,p,r);
    quicksort(S,n,p,q-1);
    quicksort(S,n,q+1,r);
  }
}

