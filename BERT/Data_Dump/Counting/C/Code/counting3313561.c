#include<stdio.h>

void func(int *,int *,int);
int n,b[2000001],c[2000001];

int main(){
  int k=0,i,j;
  int a[2000001];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i+1]);
    if(k < a[i]) k = a[i];
  }

  func(a,b,k);

  return 0;
}

void func(int *a,int *b,int k){
  int i,j;
  for(i=0;i<=k;i++){
    c[i]=0;
  }
  for(j=1;j<=n;j++){
    c[a[j]]++;
  }
  for(i=1;i<=k;i++){
      c[i]=c[i]+c[i-1];
  }
  for(j=n;j>0;j--){
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }

  for(i=1;i<=n;i++){
    if(i>1) printf(" ");
    printf("%d",b[i]);
  }
  printf("\n");
}

