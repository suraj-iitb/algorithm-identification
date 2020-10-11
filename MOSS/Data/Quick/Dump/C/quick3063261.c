#include<stdio.h>
#define N 100000
#define SENTINEL 2000000000
typedef struct number{
  char card;
  int num;
}S;
S L[N/2+2],R[N/2+2];
void merge(S A[],int s,int l,int m,int r){
  int n1=m-l;
  int n2=r-m;
  int i;
  for(i=0;i<n1;i++)L[i]=A[l+i];
  for(i=0;i<n2;i++)R[i]=A[m+i];
  L[n1].num=R[n2].num=SENTINEL;
  i=0;
  int j=0;
  for(int k=l;k<r;k++){
    if(L[i].num<=R[j].num){
      A[k]=L[i];
      i+=1;
    }
    else {
      A[k]=R[j];
      j+=1;
    }
  }
}
void mergeSort(S A[],int s,int l,int r){
  if(l+1<r){
    int m=(l+r)/2;
    mergeSort(A,s,l,m);
    mergeSort(A,s,m,r);
    merge(A,s,l,m,r);
  }
}
int partition(S a[],int s,int p,int r){
  int i,j;
  S b,x;
  x=a[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(a[j].num<=x.num){
      i++;
      b=a[i];
      a[i]=a[j];
      a[j]=b;
    }
  }
    b=a[i+1];
    a[i+1]=a[r];
    a[r]=b;

  return i+1;
}
void quicksort(S A[],int s,int p,int r){
  int q;
  if(p<r){
    q=partition(A,s,p,r);
    quicksort(A,s,p,q-1);
    quicksort(A,s,q+1,r);
  }
}
int main(){
  int a,i,w;
  int flag=1;
  S tra[N],np[N];
  char t[10];
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%s",t);
    np[i].card=tra[i].card=t[0];
    scanf("%d",&w);
    np[i].num=tra[i].num=w;
  }
  mergeSort(np,a,0,a);
  quicksort(tra,a,0,a-1);
  for(i=0;i<a;i++){
    if(np[i].card!=tra[i].card)flag=0;
  }
  if(flag==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<a;i++)printf("%c %d\n",tra[i].card,tra[i].num);
  return 0;
}

