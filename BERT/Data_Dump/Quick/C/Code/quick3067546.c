#include <stdio.h>
#define MAX 100000
#define S 100000000

struct Card {
  char suit;
  int value;
};

struct Card L[MAX/2+2], R[MAX/2+2];

void merge(struct Card A[], int n, int l, int m, int r){
  int i,j,k;
  int n1 = m-l;
  int n2 = r-m;
  for(i=0;i<n1;i++)L[i] = A[l+i];
  for(i=0;i<n2;i++)R[i] = A[m+i];
  L[n1].value = R[n2].value = S;
  i=j=0;
  for(k=l;k<r;k++){
    if(L[i].value<=R[j].value) A[k] = L[i++];
    else A[k] = R[j++];
  }
  
}

void sort(struct Card A[], int n, int l, int r){
  int m;
  if(l+1<r){
    m = (l + r) / 2;
    sort(A, n, l, m);
    sort(A, n, m, r);
    merge(A, n, l, m, r);
  }
}

int partition(struct Card A[], int n, int p, int r){
  int i,j;
  struct Card t, x;
  x = A[r];
  i = p - 1;
  for(j=p;j<r;j++){
    if(A[j].value<=x.value){
      i++;
      t = A[i];
      A[i] = A[j];
      A[j] = t;
    }
  }

  t = A[i+1];
  A[i+1] = A[r];
  A[r] = t;
  return i+1;
}

void quick(struct Card A[], int n, int p, int r){
  int q;
  if(p<r){
    q = partition(A,n,p,r);
    quick(A,n,p,q-1);
    quick(A,n,q+1,r);
  }

}

int main(){
  int n,i,v;
  struct Card A[MAX], B[MAX];
  char s[10];
  int stable = 1;
  scanf("%d", &n);

  for(i=0;i<n;i++){
 scanf("%s %d",s, &v);
 A[i].suit = B[i].suit= s[0];
 A[i].value = B[i].value = v;
  }

  sort(A,n,0,n);
  quick(B,n,0,n-1);

  for(i=0;i<n;i++){if(A[i].suit!=B[i].suit) stable=0;}

  if(stable == 1)printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++)printf("%c %d\n",B[i].suit, B[i].value);

  return 0;
}

