#include<stdio.h>
#define N 100000
#define SENTINEL 2000000000

struct card{
  char suit;
  int value;
};

struct card L[N/2+2],R[N/2+2];

void merge(struct card a[],int n,int l,int mid,int r){
  int i,j,k;
  int n1=mid-l;
  int n2=r-mid;

  for(i=0;i<n1;i++)L[i]=a[l+i];
  for(i=0;i<n2;i++)R[i]=a[mid+i];
  L[n1].value=R[n2].value=SENTINEL;
  i=j=0;
  for(k=l;k<r;k++){
    if(L[i].value<=R[j].value)a[k]=L[i++];
    else a[k]=R[j++];
    
  }

}

void mergeSort(struct card a[],int n,int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(a,n, left, mid);
    mergeSort(a,n, mid, right);
    merge(a,n, left, mid, right);
  }
}

int partition(struct card a[],int n,int p,int r){
  int i,j;
  struct card t,x;
  x=a[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(a[j].value<=x.value){
      i++;
      t=a[i];
      a[i]=a[j];
      a[j]=t;
    }
  }
  t=a[i+1];
  a[i+1]=a[r];
  a[r]=t;
  return i+1;
}

void quickSort(struct card A[],int n,int p,int r){
  int q;
  if (p < r){
    q = partition(A,n, p, r);
    quickSort(A,n, p, q-1);
    quickSort(A, n,q+1, r);
  }
}

int main(){
  int n,i,v;
  struct card a[N],b[N];
  char s[10];
  int stable=1;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s%d",s,&v);
    a[i].suit=b[i].suit=s[0];
  a[i].value=b[i].value=v;
  }

  mergeSort(a,n,0,n);
  quickSort(b,n,0,n-1);

  for(i=0;i<n;i++)if(a[i].suit!=b[i].suit)stable=0;

  if(stable==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++)printf("%c %d\n",b[i].suit,b[i].value);

  return 0;
  
}

