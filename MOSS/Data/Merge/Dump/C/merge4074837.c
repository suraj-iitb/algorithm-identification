#include<stdio.h>
#define MAX 500000
#define CM 2000000000
int key=0;
int L[MAX/2 + 2],R[MAX/2 + 2];

void marge(int*,int,int,int,int);
void margesort(int*,int,int,int);

int main(){
  int n,i,a[MAX];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  margesort(a,n,0,n);

  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",key);

  return 0;
}

void marge(int a[],int n,int o,int p,int q){
  int x,y,i,j,k;

  x=p-o;
  y=q-p;
  for(i=0;i<x;i++){
    L[i]=a[o+i];
  }
  for(i=0;i<y;i++){
    R[i]=a[p+i];
  }
  L[x]=R[y]=CM;

  i=0;
  j=0;
  for(k=o;k<q;k++){
    key++;
    if(L[i]<=R[j]){
      a[k]=L[i++];
    }
    else{
      a[k]=R[j++];
    }
  }
}

void margesort(int a[],int n,int o,int p){
  int m;
  if(o+1<p){
    m=(o+p)/2;
    margesort(a,n,o,m);
    margesort(a,n,m,p);
    marge(a,n,o,m,p);
  }
}

