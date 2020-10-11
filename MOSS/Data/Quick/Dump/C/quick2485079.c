#include <stdio.h>
#define MAX 100000
#define SENTINEL 1000000000
struct Card{
  char suit;
  int value;
};
struct Card L[MAX/2+2],R[MAX/2+2];
int partition(struct Card A[], int n,int p,int r){
  int i,j;
  struct Card temp,x;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].value<=x.value){
      i++;
      temp=A[i];
      A[i]=A[j];
      A[j]=temp;
    }
  }
  temp=A[i+1];
  A[i+1]=A[r];
  A[r]=temp;
  return i+1;
}
void Merge(struct Card A[],int n,int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int i,j,k;
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1].value=SENTINEL;
  R[n2].value=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i].value<=R[j].value){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
  }
}
void Merge_Sort(struct Card A[],int n,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    Merge_Sort(A,n,left,mid);
    Merge_Sort(A,n,mid,right);
    Merge(A,n,left,mid,right);
  }
}
void Quick_Sort(struct Card A[],int n,int p,int r){
  int q;
  if(p<r){
    q=partition(A,n,p,r);
    Quick_Sort(A,n,p,q-1);
    Quick_Sort(A,n,q+1,r);
  }
}
int main(){
  int n,i,v;
  struct Card A[MAX],B[MAX];
  char str[10];
  int stable=1;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %d",str,&v);
    A[i].suit=str[0];
    B[i].suit=str[0];
    A[i].value=v;
    B[i].value=v;
  }
  Merge_Sort(A,n,0,n);
  Quick_Sort(B,n,0,n-1);
  for(i=0;i<n;i++){
    if(A[i].suit!=B[i].suit) stable=0;
  }
  if(stable==1) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",B[i].suit,B[i].value);
  }
  return 0;
}
