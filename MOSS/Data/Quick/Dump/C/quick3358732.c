#include <stdio.h>
#define MAX 100000
#define N 2000000000
struct Card {
  char suit;
  int value;
};
struct Card L[MAX/2+2],R[MAX/2+2];
void kansuu1(struct Card A[],int n,int left,int mid,int right){
  int i,j,k;
  int a=mid-left;
  int b=right-mid;
  for(i=0;i<a;i++) L[i]=A[left+i];
  for(i=0;i<b;i++) R[i]=A[mid+i];
  L[a].value=R[b].value=N;
  i=j=0;
  for(k=left;k<right;k++){
    if(L[i].value<=R[j].value){
      A[k]=L[i++];
    }else{
      A[k]=R[j++];
    }
  }
}
void kansuu2(struct Card A[],int n,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    kansuu2(A,n,left,mid);
    kansuu2(A,n,mid,right);
    kansuu1(A,n,left,mid,right);
  }
}
int kansuu3(struct Card A[],int n,int p,int r){
  int i,j;
  struct Card t,x;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].value<=x.value){
      i++;
      t=A[i];A[i]=A[j];A[j]=t;
    }
  }
  t=A[i+1];A[i+1]=A[r];A[r]=t;
  return i+1;
}
void kansuu4(struct Card A[],int n,int p,int r){
  int q;
  if(p<r){
    q=kansuu3(A,n,p,r);
    kansuu4(A,n,p,q-1);
    kansuu4(A,n,q+1,r);
  }
}
int main(void){
  int n,i,v;
  int stable=1;
  struct Card A[MAX],B[MAX];
  char C[10];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %d",C,&v);
    A[i].suit=B[i].suit=C[0];
    A[i].value=B[i].value=v;
  }
  kansuu2(A,n,0,n);
  kansuu4(B,n,0,n-1);
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

