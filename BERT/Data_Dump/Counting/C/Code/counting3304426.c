#include<stdio.h>
void countingsort(int n,int a[],int b[],int k){
  int i,j,c[k+1];
  for(i=0;i<=k;i++)c[i]=0;
  for(j=1;j<=n;j++)c[a[j]]++;
  for(i=1;i<=k;i++)c[i]=c[i]+c[i-1];
  for(j=n;j>=1;j--){
    b[c[a[j]]]=a[j];
    c[a[j]]--;
  }
}

int main(){
  int n,a[2000000],i,b[2000000],k=0;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
    if(k<a[i])k=a[i];
  }
  countingsort(n,a,b,k);
  for(i=1;i<n;i++)printf("%d ",b[i]);
  printf("%d\n",b[n]);
  return 0;
}

