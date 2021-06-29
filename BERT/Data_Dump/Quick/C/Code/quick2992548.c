#include<stdio.h>
#define MAX 100000
#define SENTINEL 2000000000

typedef struct{
  char suit;
  int value;
}card;

card Left[MAX/2+2],Right[MAX/2+2];

void merge(card ary[],int n,int left,int mid,int right){
  int i,j,k;
  int n1,n2;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++)Left[i]=ary[left+i];
  for(i=0;i<n2;i++)Right[i]=ary[mid+i];
  Left[n1].value=Right[n2].value=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(Left[i].value<=Right[j].value){
      ary[k]=Left[i++];
    }
    else{
      ary[k]=Right[j++];
    }
  }
}

void mergesort(card ary[],int n,int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergesort(ary,n,left,mid);
    mergesort(ary,n,mid,right);
    merge(ary,n,left,mid,right);
  }
}

int partition(card a[],int n,int p,int r){
  int i,j;
  card t,x;
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

void quicksort(card a[],int n,int p,int r){
  int q;
  if(p<r){
    q=partition(a,n,p,r);
    quicksort(a,n,p,q-1);
    quicksort(a,n,q+1,r);
  }
}

int main(){
  int n,i,v;
  card a[MAX],b[MAX];
  char s[10];
  int flag=1;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s%d",s,&v);
    a[i].suit=b[i].suit=s[0];
    a[i].value=b[i].value=v;
  }

  mergesort(a,n,0,n);
  quicksort(b,n,0,n-1);

  for(i=0;i<n;i++){
    if(a[i].suit!=b[i].suit)flag=0;
  }
  if(flag==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",b[i].suit,b[i].value);
  }
  return 0;
}

