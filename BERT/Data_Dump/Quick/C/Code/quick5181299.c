#include<stdio.h>
#include<stdlib.h>

#define SENTINEL 2000000000

long int cnt=0;

typedef struct box{
        char a;
        int b;
} card;
void merge(card *,int,int,int);
void mergeSort(card*,int,int);
int part(card*,int,int);
void quick(card*,int,int);
int main()
{
        int j,m;
        card *E;
        card *V;
        int l,r;
        int check=0;
        scanf("%d",&m);
        E = (card*)malloc(sizeof(card)*m+1);
        V = (card*)malloc(sizeof(card)*m+1);
        for(j=0;j<m;j++) {
                scanf("%s",&E[j].a);
                scanf("%d",&E[j].b);
                V[j].a=E[j].a;
                V[j].b=E[j].b;
        }
        quick(E,0,m-1);
         l=0;
    r=m;
        mergeSort(V,l,r);
        for(j=0;j<m;j++) if(E[j].a!=V[j].a) check=1;
        if(check==0)printf("Stable\n");
        else printf("Not stable\n");
        for(j=0;j<m;j++) printf("%c %d\n",E[j].a,E[j].b);
        free(E);
        free(V);
        return 0;
}
void merge(card *X,int l,int mid,int r){
  int p1 = mid - l;
  int p2 = r - mid;
  card L[p1+1],R[p2+1];
    int k,i,j;
  for (i=0;i<p1;i++) {
        L[i].a = X[l + i].a;
        L[i].b = X[l + i].b;
  }
  for (i=0;i<p2;i++) {
        R[i].a = X[mid + i].a;
        R[i].b = X[mid + i].b;
  }
  L[p1].b = SENTINEL;
  R[p2].b = SENTINEL;
  i = 0;
  j = 0;

  for(k=l;k<r;k++){
    if(L[i].b<=R[j].b){
      X[k].a = L[i].a;
      X[k].b = L[i].b;
      i=i+1;
    }else{
      X[k].a = R[j].a;
       X[k].b = R[j].b;
      if(L[i].b!=SENTINEL) cnt+=(p1-i);
      j = j + 1;
    }
  }
}

void mergeSort(card *X,int l,int r)
{
  int mid,i;
  if(l+1<r){
    mid = (l+ r)/2;
    mergeSort(X, l, mid);
    mergeSort(X, mid, r);
    merge(X, l, mid, r);
  }
}


int part(card *X,int q,int r)
{
        int x = X[r].b;
        int box,j,i = q-1;

        int k;

        char s;
          for( j = q ; j < r ; j++){
                if( X[j].b <= x){
                        i = i+1;
                        box=X[i].b;
                        s=X[i].a;
        X[i].b=X[j].b;
                        X[i].a=X[j].a;
                        X[j].b=box;
                        X[j].a=s;
                }
        }
        box=X[i+1].b;
        s=X[i+1].a;
        X[i+1].b=X[r].b;
        X[i+1].a=X[r].a;
        X[r].b=box;
        X[r].a=s;
        return i+1;
}
void quick(card *A,int p ,int r)
{
        int q;
        if(p<r){
                q=part(A,p,r);
                   quick(A,p,q-1);
                quick(A,q+1,r);
        }
}

