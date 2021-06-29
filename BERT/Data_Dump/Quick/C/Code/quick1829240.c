#include <stdio.h>

#define MAX 100000
#define INFINITY 2000000000

struct Card{
  char s;
  int value;
};

struct Card L[MAX/2+2],R[MAX/2+2];

void marge(struct Card[],int,int,int);
void margeSort(struct Card[],int,int);
int partition(struct Card[],int,int,int);
void quickSort(struct Card[],int,int,int);

int main(){
  int n,i,j,v;
  int stable=1;
  struct Card A[MAX],B[MAX];
  char S[10];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s %d",S,&v);
    A[i].s=B[i].s=S[0];
    A[i].value=B[i].value=v;
  }
  margeSort(A,0,n);
  quickSort(B,n,0,n-1);
  for(i=0;i<n;i++){
    if(A[i].s != B[i].s)stable=0;
  }

  if(stable ==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",B[i].s,B[i].value);
  }

  return 0;
}

void marge(struct Card A[],int left,int mid,int right)
{
  int i,j,k,n1,n2;

   n1=mid-left;
   n2=right-mid;
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1].value=INFINITY;
  R[n2].value=INFINITY;
  i=0;
  j=0;
  for(k=left;k<right;k++)
    {
      if(L[i].value<=R[j].value){
	A[k]=L[i++];
      }
      else {
	A[k]=R[j++];
      }
    }
}

void margeSort(struct Card A[],int left,int right)
{
  int mid;  
  if(left+1<right){
    mid = (left+right)/2;
    margeSort(A,left,mid);
    margeSort(A,mid,right);
    marge(A,left,mid,right);
  }
}


int partition(struct Card A[],int n,int p,int r){

  int i,j;
  struct Card t,x;
  x=A[r];
  i=p-1;

  for(j=p;j<r;j++){
    if(A[j].value<=x.value){
      i++;
      t=A[i];
      A[i]=A[j];
      A[j]=t;
    }
  }

  t=A[i+1];
  A[i+1]=A[r];
  A[r]=t;
  return i+1;
}

void quickSort(struct Card A[],int n,int p,int r){
  int q;
  if(p<r){
    q=partition(A,n,p,r);
    quickSort(A,n,p,q-1);
    quickSort(A,n,q+1,r);
  }
}
