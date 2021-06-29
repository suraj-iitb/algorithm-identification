#include <stdio.h>
#define N 100
void change(int *,int *);
int k=0;

int main(){
  int i,j,n,mina,a[N];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);
  for(i=0;i<n;i++){
    mina=i;
    for(j=i;j<n;j++){
      if(a[mina]>a[j])mina=j;
    }
    if(a[i]!=a[mina])change(&a[i],&a[mina]);
  }
  for(i=0;i<n-1;i++)printf("%d ",a[i]);
  printf("%d\n%d\n",a[i],k);
  return 0;
}

void change(int *x,int *y){
  int i;
  i=*x;
  *x=*y;
  *y=i;
  k++;
}

