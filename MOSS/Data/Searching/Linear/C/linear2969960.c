#include<stdio.h>
int linesearch(int *a,int k,int n);
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
    iden=linesearch(a,alt,n);
    if(iden==1){
      cnt++;
    }
  }
  printf("%d\n",cnt);
  return 0;
}
  int linesearch(int *a, int k,int n){
  int i=0;
  a[n]=k;
  while(a[i]!=k){
    if(i==n-1)return 0;
     i++;
  }
  return 1;
}

