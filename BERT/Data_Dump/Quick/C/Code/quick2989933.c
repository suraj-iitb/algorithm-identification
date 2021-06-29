#include <stdio.h>
#include <stdlib.h>
struct card{
  char handle;
  int num;
};
void quicksort(struct card *,int,int);
int partition(struct card *,int,int);
void merge(struct card *,int,int,int);
void mergesort(struct card *,int,int);
int main(){
  int n,i;
  char dummy[10];
  struct card A[100000],c[100000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %d",dummy,&A[i].num);
    A[i].handle=dummy[0];
    c[i]=A[i];
  }
  mergesort(A,0,n);
  quicksort(c,0,n-1);
  int cnt=0;
  for(i=0;i<n;i++){
    if(A[i].handle!=c[i].handle){
      printf("Not stable\n");
      cnt++;
      break;
    }
  }
  if(cnt==0)printf("Stable\n");
  for(i=0;i<n;i++){
      printf("%c %d\n",c[i].handle,c[i].num);
  }
  return 0;
}
void quicksort(struct card *A,int p,int r){
  int q;
  if(p<r){
    q=partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}
int partition(struct card *A,int p,int r){
  int i,cnt=p-1,q;
  q=A[r].num;
  struct card j;
  for(i=p;i<r;i++){
    if(A[i].num<=q){
      cnt++;
      j=A[i];
      A[i]=A[cnt];
      A[cnt]=j;
    }
  }
  j=A[cnt+1];
  A[cnt+1]=A[r];
  A[r]=j;
  return cnt+1;
}
void mergesort(struct card *c,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(c,left,mid);
    mergesort(c,mid,right);
    merge(c,left,mid,right);
  }
}
void merge(struct card *c,int left,int mid,int right){
  int n1=mid-left,n2=right-mid;
  struct card *L,*R;
  L=malloc(sizeof(struct card)*(n1+2));
  R=malloc(sizeof(struct card)*(n2+2));
  int i;
  for(i=0;i<n1;i++)L[i]=c[i+left];
  for(i=0;i<n2;i++)R[i]=c[i+mid];
  L[n1].num=R[n2].num=2000000000;
  int j=0,k;
  i=0;
  for(k=left;k<right;k++){
    if(L[i].num<=R[j].num)c[k]=L[i++];
    else c[k]=R[j++];
  }
  free(L);
  free(R);
}


