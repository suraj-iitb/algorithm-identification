#include <stdio.h>

#define N_MAX 2000000
#define N 10000

void myC_sort(int *,int *,int *,int,int);

int main(){
  int a[N_MAX+1]={0},b[N_MAX+1]={0},c[N+1]={0},n,i,max,in;
  scanf("%d",&n);
  for(i=1; i<=n; i++){
    scanf("%d",&in);
    if(in>max) max=in;
    a[i]=in;
  }

  myC_sort(a,b,c,max,n);
  for(i=1; i<n; i++){
    printf("%d ",b[i]);
  }
  printf("%d\n",b[i]);
  
  return 0;
}

void myC_sort(int *a,int *b,int *c,int k,int n){
  int i;
  for(i=0; i<=k; i++) c[i]=0;
  for(i=1; i<=n; i++) c[a[i]]=c[a[i]]+1;
  for(i=1; i<=k; i++) c[i]=c[i]+c[i-1];
  for(i=n; i>=1; i--){
    b[c[a[i]]]=a[i];
    c[a[i]]=c[a[i]]-1;
  }
}

