#include<stdio.h>
#include<stdlib.h>
int sum=0;
void merge(int *,int,int,int);
void sort(int *,int,int);

int main(){
  int n,i,*S;
  scanf("%d",&n);
  S=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  sort(S,0,n);
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",S[i]);
    else printf("%d ",S[i]);
  }
  printf("%d\n",sum);
  free(S);
  return 0;
}

void sort(int *a,int L,int R){
  int mid;
  if(L+1<R){
    mid =(L+R)/2;
    sort(a,L,mid);
    sort(a,mid,R);
    merge(a,L,mid,R);
  }
}

void merge(int *a,int L,int mid,int R){
  int n1=mid-L,n2=R-mid,i,j,k;
  int l[n1],r[n2];
  for(i=0;i<n1;i++){
    l[i]=a[L+i];
  }
  for(i=0;i<n2;i++){
    r[i]=a[mid+i];
  }
  l[n1]=1000000001;
  r[n2]=1000000001;
  i=0;
  j=0;
  for(k=L;k<R;k++){
    if(l[i]>r[j]){
      a[k]=r[j];
      j++;
    }else{
      a[k]=l[i];
      i++;
    }
    sum++;
  }
}

