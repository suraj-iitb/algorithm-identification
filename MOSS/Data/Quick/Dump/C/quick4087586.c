#include<stdio.h>
#define MAX 100000

typedef struct
{
  char mark;
  int num;
}CARD;

CARD L[MAX/2+2],R[MAX/2+2];

void merge(CARD*,int,int,int,int);
void mergesort(CARD*,int,int,int);
int partition(CARD*,int,int,int);
void quicksort(CARD*,int,int,int);

int main()
{
  int n,i,y,flag=1;
  char x[10];
  scanf("%d",&n);
  CARD A[MAX],B[MAX];
  
for(i=0;i<n;i++){
 scanf("%s %d",x,&y);
 A[i].mark=B[i].mark=x[0];
 A[i].num=B[i].num=y;
                 }
 mergesort(A,n,0,n);
 quicksort(B,n,0,n-1);

 for(i=0;i<n;i++){
   if(A[i].num!=B[i].num) flag=0;
   if(A[i].mark!=B[i].mark) flag=0;
                 }
 if(flag==1)
   printf("Stable\n");
 else 
   printf("Not stable\n");
 for(i=0;i<n;i++){
   printf("%c %d\n",B[i].mark,B[i].num);
                 }
 return 0;
}
void merge(CARD *A,int n,int left,int mid,int right)
{
  int n1,n2;
  n1=mid-left;
  n2=right-mid;
  int i,j,k;
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1].num=R[n2].num=2000000000;
  i=j=0;
  for(k=left;k<right;k++){
    if(L[i].num<=R[j].num) A[k]=L[i++];
    else A[k] = R[j++];
                        }
}
void mergesort(CARD* A,int n,int left,int right)
{
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(A,n,left,mid);
    mergesort(A,n,mid,right);
    merge(A,n,left,mid,right);
                  }
}
int partition(CARD*B,int n,int p,int r)
{
  CARD x,s;
  int i,j;
  x=B[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(B[j].num<=x.num){
      i++;
      s=B[i];
      B[i]=B[j];
      B[j]=s;          }
                 }
  s=B[i+1];
  B[i+1]=B[r];
  B[r]=s;

  return i+1;
}

void quicksort(CARD *B,int n,int p,int r)
{
  int q;
  if(p<r){
    q=partition(B,n,p,r);
    quicksort(B,n,p,q-1);
    quicksort(B,n,q+1,r);
          }
}


