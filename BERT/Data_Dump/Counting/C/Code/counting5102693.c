#include<stdio.h>
int main(){
  int n,i,j,a[2000000],b[2000000],c[10000];
  scanf("%d",&n);
  for(i=0;i<10000;i++)c[i]=0;
  for(i=0;i<n;i++){
    scanf("%d",&a[i+1]);
    c[a[i+1]]++;
  }
  for(i=1;i<=10000;i++)c[i]=c[i]+c[i-1];
  for(j=1;j<=n;j++){
    b[c[a[j]]]=a[j];
    c[a[j]]--;
  }
  for(i=1;i<=n;i++){
    if(i>1)printf(" ");
    printf("%d",b[i]);
  }
  printf("\n");
  return 0;
}
