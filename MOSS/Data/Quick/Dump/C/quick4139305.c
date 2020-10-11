#include <stdio.h>
#define N 100000
#define SEN 2000000000

struct Point{
  int value;
  char gou;
};

struct Point L[N/2+2],R[N/2+2];
void merge (struct Point hi[],int n,int l,int m,int r);
void mergesort (struct Point hi[],int n,int l,int r);
int partition (struct Point hi[],int n,int l,int r);
void quicksort(struct Point hi[],int n,int l,int r);

int main(){
  int i,n,st;
  char hiii[10];
  struct Point hi[N],hii[N];
  int judge=1;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s %d",hiii,&st);
    hi[i].gou=hii[i].gou=hiii[0];
    hi[i].value=hii[i].value=st;
  }

  mergesort(hi,n,0,n);
  quicksort(hii,n,0,n-1);

  for(i=0;i<n;i++){
    if(hi[i].gou != hii[i].gou)
      judge=0;
  }

  if(judge==1)
    printf("Stable\n");
  else
    printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",hii[i].gou,hii[i].value);
  }

  return 0;
}
  
void merge (struct Point hi[],int n,int l,int m,int r){
  int s,t;
  int i=0,j=0,p;
  s=m-l;
  t=r-m;
  for(i=0;i<s;i++)
    L[i]=hi[l+i];
  for(i=0;i<t;i++)
    R[i]=hi[m+i];
  
  L[s].value=R[t].value=SEN;

  i=j=0;
  
  for (p=l;p<r;p++){
    if (L[i].value<=R[j].value){
      hi[p]=L[i++];
    }else{
      hi[p]=R[j++];
    }
  }
}

void mergesort (struct Point hi[],int n,int l,int r){
  int m;
  if (l+1<r){
    m=(l+r)/2;
    mergesort(hi,n,l,m);
    mergesort(hi,n,m,r);
    merge(hi,n,l,m,r);
  }
}

int partition (struct Point hi[],int n,int l,int r){
  int i,j;
  struct Point x,q;
  x=hi[r];
  i=l-1;

  for(j=l;j<r;j++){
    if(hi[j].value<=x.value){
      i++;
      q=hi[i];
      hi[i]=hi[j];
      hi[j]=q;
    }
  }
  q=hi[i+1];
  hi[i+1]=hi[r];
  hi[r]=q;

  return i+1;
}

void quicksort(struct Point hi[],int n,int l,int r){
  int a;
  if(l<r){
    a=partition(hi,n,l,r);
    quicksort(hi,n,l,a-1);
    quicksort(hi,n,a+1,r);
  }
}

