#include<stdio.h>

#define L 100000
#define M 2000001

int a[M],b[M],c[M];
int n,i,j;

int main(){
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }

  for(j=0;j<L;j++){
    c[j]=0;
    b[j]=0;
  }

  for(i=1;i<=n;i++){
    c[a[i]]++;
  }

  for(i=1;i<10001;i++){
    c[i] += c[i-1];
  }

  for(i=n;i>0;i--){
    b[c[a[i]]] = a[i];
    c[a[i]]--;
  }

  for(i=1;i<n;i++){
    printf("%d ",b[i]);
  }
  printf("%d\n",b[n]);

  return 0;
}

  
