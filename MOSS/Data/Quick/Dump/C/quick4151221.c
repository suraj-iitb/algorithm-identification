#include<stdio.h>
#define MAX 100000
#define SE 2000000000

struct Card{
  char su;
  int nb;
};

struct Card A[MAX/2+2],B[MAX/2+2];

void mg(struct Card C[],int n,int l,int ce,int r){
  int i,j,k;
  int a1 = ce -l;
  int a2 = r - ce;
  for(i = 0;i<a1;i++)
    A[i] = C[l +i];
  for(i = 0;i<a2;i++)
    B[i] = C[ce + i];
  A[a1].nb = B[a2].nb = SE;
  i = j = 0;
  for(k = l;k<r;k++){
    if(A[i].nb<=B[j].nb){
      C[k] = A[i++];
    }else{
      C[k] = B[j++];
    }
  }
}

void mgsort(struct Card C[],int x,int le,int ri){
  int mid;
  if(le +1<ri){
    mid = (le+ri)/2;
    mgsort(C,x,le,mid);
    mgsort(C,x,mid,ri);
    mg(C,x,le,mid,ri);
  }
}

int par(struct Card C[],int x,int p,int q){
  int i,j;
  struct Card s,t;
  t = C[q];
  i = p-1;
  for(j = p;j<q;j++){
    if(C[j].nb<=t.nb){
      i++;
      s = C[i];
      C[i] = C[j];
      C[j] = s;
    }
  }
  s = C[i+1];
  C[i+1] = C[q];
  C[q] = s;
  return i+1;
}

void qsort(struct Card C[],int x,int p,int q){
  int w;
  if(p<q){
    w = par(C,x,p,q);
    qsort(C,x,p,w-1);
    qsort(C,x,w+1,q);
  }
}

int main(){

  int x,i,v;
  struct Card C[MAX],D[MAX];
  char  Z[10];
  int sb = 1;

  scanf("%d",&x);

  for(i = 0;i<x;i++){
    scanf("%s %d",Z,&v);
    C[i].su = D[i].su = Z[0];
    C[i].nb = D[i].nb = v;
  }
  mgsort(C,x,0,x);
  qsort(D,x,0,x-1);

  for(i = 0;i<x;i++){
    if(C[i].su!=D[i].su) sb = 0;
  }

  if(sb == 1) printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0;i<x;i++){
    printf("%c %d\n",D[i].su,D[i].nb);
  }
  return 0;
}
