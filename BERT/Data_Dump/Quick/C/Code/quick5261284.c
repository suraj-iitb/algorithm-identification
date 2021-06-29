#include<stdio.h>

typedef struct card{
  char suit;
  int value;
}card;

int partition(card a[],int p,int r){
  int i,j;
  card t,x;
  x=a[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(a[j].value<=x.value){
      i=i+1;
      t=a[i];
      a[i]=a[j];
      a[j]=t;
    }
  }
  t=a[i+1];a[i+1]=a[r];a[r]=t;
  return i+1;
}

void quicksort(card a[],int p,int r){
  int q;
  if(p<r){
    q=partition(a,p,r);
    quicksort(a,p,q-1);
    quicksort(a,q+1,r);
  }
  return;
}

//安定か否かを確認するためにマージソート
void merge(card b[],int left,int mid,int right){
  int n1,n2,i,k;
  n1=mid-left;
  n2=right-mid;

  card l[n1+1],r[n2+1];
  for(i=0;i<n1;i++){
    l[i]=b[left+i];
  }
  for(i=0;i<n2;i++){
    r[i]=b[mid+i];
  }
  l[n1].value=2000000000;
  r[n2].value=2000000000;
  i=0;
  int j=0;
  for(k=left;k<right;k++){
    if(l[i].value<=r[j].value){
      b[k]=l[i];
      i++;
    }else{
      b[k]=r[j];
      j++;
    }
  }
  return;
}

void mergesort(card b[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(b,left,mid);
    mergesort(b,mid,right);
    merge(b,left,mid,right);
  }
  return;
}

int main(void){
  int n,i,flag=0,v;
  char s[200];
  card a[100005],b[100005];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %d",s,&v);
    a[i].suit=s[0];
    a[i].value=v;
    b[i]=a[i];//比較用にコピー
  }

  quicksort(a,0,n-1);
  mergesort(b,0,n);
  
  for(i=0;i<n;i++){
    if(a[i].suit!=b[i].suit){flag=1;}
  }
  if(flag==0){printf("Stable\n");}
  else{printf("Not stable\n");}

  for(i=0;i<n;i++){
    printf("%c %d\n",a[i].suit,a[i].value);
  }
  return 0;
}
