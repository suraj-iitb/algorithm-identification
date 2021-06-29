#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>

int mf(int*,int,int);
int sort(int*,int,int,int);

int n,count =0;
int main(){
  int i,a[500000];
  scanf("%d",&n);
  for(i=0;i<n;i++)  scanf("%d",&a[i]);
  mf(a,0,n);
  i=0;
  printf("%d",a[i]);
  for(i=1;i<n;i++)
  printf(" %d",a[i]);
  
  printf("\n%d\n",count);
}
int mf(int *a,int l,int r){
  if(l+1<r){
  int mid;
  mid=(l+r)/2;
    mf(a,l,mid);
    mf(a,mid,r);
    sort(a,l,mid,r);

  }

}
int sort(int *a,int l,int m,int r){
  int n1,n2;
  int i,j,k,*la,*ra;
  n1=m-l;
  n2=r-m;
  la = malloc(sizeof(int)*n1+1);
  ra = malloc(sizeof(int)*n2+1);
  
  
  for(i=0;i<n1;i++) la[i]=a[l+i];
  la[i]=-1;
  for(i=0;i<n2;i++) ra[i]=a[m+i];
  ra[i]=-1;
  i=0;
  j=0;
  for(k=l;k<r;k++){
    if((la[i] < ra[j] || ra[j] == -1) && la[i] != -1){
      a[k]=la[i];
      i++;
    }else{
      a[k]=ra[j];
      j++;

    }
    count++;

  }
  free(ra);
  free(la);
}

