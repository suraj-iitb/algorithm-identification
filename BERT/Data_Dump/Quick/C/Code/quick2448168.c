#include<stdio.h>
#define MAX 100000
#define SENTINEL 2000000000
struct A{
  char m;
  int value;
};
struct A L[MAX/2+2],R[MAX/2+2];
void merge(struct A a[],int n,int left,int mid,int right){
  int i,j,k;
  int n1=mid-left;
  int n2=right-mid;
  for(i=0;i<n1;i++)L[i]=a[left+i];
  for(i=0;i<n2;i++)R[i]=a[mid+i];
  L[n1].value=R[n2].value=SENTINEL;
  i=j=0;
  for(k=left;k<right;k++){
    if(L[i].value<=R[j].value)a[k]=L[i++];
    else a[k]=R[j++];
  }

}
void mergeSort(struct A a[],int n,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(a,n,left,mid);
    mergeSort(a,n,mid,right);
    merge(a,n,left,mid,right);
  }
}int partition(struct A a[],int n,int p,int r){
  struct A x,y;
  int i,j;
  x=a[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(a[j].value<=x.value){
      i++;
      y=a[i];
      a[i]=a[j];
      a[j]=y;
    }
  }
  y=a[i+1];
  a[i+1]=a[r];
  a[r]=y;
  return i+1;
}
void quickSort(struct A a[],int n,int p,int r){
  int q;
  if(p<r){
    q=partition(a,n,p,r);
    quickSort(a,n,p,q-1);
    quickSort(a,n,q+1,r);
  }
}
int main(){
  int n,i,v;
  struct A a[MAX],b[MAX];
  char S[10];
  int stable=1;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %d",S,&v);
    a[i].m=b[i].m=S[0];
    a[i].value=b[i].value=v;
  }
  mergeSort(a,n,0,n);
  quickSort(b,n,0,n-1);
  for(i=0;i<n;i++){
    if(a[i].m!=b[i].m)stable=0;  
  }
  if(stable==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",b[i].m,b[i].value);
  }
  return 0;
}
