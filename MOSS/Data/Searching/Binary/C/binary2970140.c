#include<stdio.h>
int binary(int *a,int k,int n);
int main()
{
  int i,j,n,m,alt,cnt=0,iden;
  scanf("%d",&n);
  int a[n+1];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&m);
  for(j=0;j<m;j++){
    scanf("%d",&alt);
    iden=binary(a,alt,n);
    if(iden==1){
      cnt++;
    }
  }
  printf("%d\n",cnt);
  return 0;
}
int binary(int *a,int k,int n){
  int left=0,right=n,mid,i;
  while(left<right){
    mid=(left+right)/2;
    if(a[mid]==k){
      return 1;
    }
    else if(k<a[mid]){
      right=mid;
    }
    else{
      left=mid+1;
    }
  }
  return 0;
}

