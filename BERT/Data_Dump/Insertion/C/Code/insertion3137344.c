#include<stdio.h>
#define N 100

void display(int,int[N]);

int main(){
  int n,i,a[N];
  int j,v;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
display(n,a);
  for(i=1;i<=n-1;i++){
    v = a[i];
    j = i-1;
    while( (j>=0) && (a[j]>v) ){
      a[j+1] = a[j];
      j--;
      a[j+1] = v;
    }
    display(n,a);
  }

  return 0;
}

void display(int n,int a[N]){
  int i;

  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
printf("%d\n",a[i]);
}

