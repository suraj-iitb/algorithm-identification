#include<stdio.h>
int teto(int,int,int);
int teto2(int,int);
int n,a[500005];
int n1,count=0,i,k,j,n2,L[500005],R[500005];

int main(void){
  int i,left,right;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  left=0;
  right=n;
  teto2(left,right);
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

teto(int left,int mid,int right){
  n1=mid-left;
  n2=right-mid;
  for (i=0;i<n1;i++){
    L[i]=a[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=a[mid+i];
  }
  L[n1]=1000000001;
  R[n2]=1000000001;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      count++;
      a[k]=L[i];
      i=i+1;
    }
    else{
      count++;
      a[k]=R[j];
      j=j+1;
    }
  }
}

teto2(int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    teto2(left,mid);
    teto2(mid,right);
    teto(left,mid,right);
  }
}
