#include <stdio.h>
#define Large 200000000
struct Card {
  char s;
  int val;
};

struct Card L[50002],R[50002];

void merge1(struct Card A[],int n,int l,int m,int r){
  int n1,n2,i;
  n1=m-l;     //?????´???????????¨
  n2=r-m;     //?????´???????????¨
  for(i=0;i<n1;i++){
    L[i]=A[l+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[m+i];
  }
  L[n1].val=Large;
  R[n2].val=Large;
  int i1=0,i2=0,j;
  for(j=l;j<r;j++){
    if(L[i1].val<=R[i2].val){
      A[j]=L[i1];
      i1++;
    }else{
      A[j]=R[i2];
      i2++;
    }
  }
}

void mergeSort(struct Card A[],int n,int l, int r){
  int m;
  if(l+1<r){
      m=(r+l)/2;
      mergeSort(A,n,l,m);
      mergeSort(A,n,m,r);
      merge1(A,n,l,m,r);
  }
}
int partition(struct Card A[],int n,int p, int r){
    int i,j;
    struct  Card x,kari;
    x=A[r];
    i=p-1;
    for(j=p;j<r;j++){
      if(A[j].val<=x.val){
        i++;
        kari=A[i];
        A[i]=A[j];
        A[j]=kari;
      }
    }
    kari=A[i+1];
    A[i+1]=A[r];
    A[r]=kari;
    return i+1;
}
void quickSort(struct Card A[],int n,int p, int r){
  int q;
  if(p<r){
    q=partition(A,n,p,r);
    quickSort(A,n,p,q-1);
    quickSort(A,n,q+1,r);
  }
}

int main(int argc, char const *argv[]) {
  int n,i,v;
  struct Card A[100000],B[100000];
  char S[10];
  int flag=1;

  scanf("%d",&n);

  for (i = 0; i < n; i++) {
    scanf("%s %d", S,&v);
    A[i].s=B[i].s=S[0];
    A[i].val=B[i].val=v;
  }

  mergeSort(A,n,0,n);
  quickSort(B,n,0,n-1);

  for(i=0;i<n;i++){
    if(A[i].s!=B[i].s) flag=0;
  }
  if(flag==1) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",B[i].s,B[i].val);
  }
  return 0;
}
