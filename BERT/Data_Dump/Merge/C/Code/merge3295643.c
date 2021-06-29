#include<stdio.h>
#include<stdlib.h>
#define N 500000
int cnt=0;
void merge(int *,int,int,int);
void mergesort(int *,int,int);
int main(){
  int n,num[N],i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&num[i]);

  mergesort(num,0,n);
  for(i=0;i<n;i++){
    if(i!=0)
      printf(" ");
    printf("%d",num[i]);
  }
  printf("\n%d\n",cnt);
}
void merge(int num[],int l,int m,int r){
  int i,j,k,n1,n2,*L,*R;
  n1=m-l;
  n2=r-m;
  L=(int *)malloc((n1+1)*sizeof(int));
  R=(int *)malloc((n2+1)*sizeof(int));
  for(i=0;i<n1;i++){
    L[i]=num[l+i];
  }
  for(i=0;i<n2;i++){
    R[i]=num[m+i];
  }
  L[n1]=1000000001;
  R[n2]=1000000001;
  i=0;j=0;
  for(k=l;k<r;k++){
    cnt++;
    if(L[i]<=R[j])
      num[k]=L[i++];
    else
      num[k]=R[j++];
  }
  
}
void mergesort(int num[],int l,int r){
  if(l+1<r){
    int m=(l+r)/2;
    mergesort(num,l,m);
    mergesort(num,m,r);
    merge(num,l,m,r);
  }
}

