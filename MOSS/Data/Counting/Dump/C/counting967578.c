#include<stdio.h>

int a[2000010],b[2000010],c[2000010];

void countingSort(int MAX, int n){
  int i;
  for(i=0;i<=MAX;i++) c[i]=0;

  for(i=1;i<=n;i++) c[a[i]]++;

  for(i=1;i<=MAX;i++) c[i]+=c[i-1];

  for(i=n;i>=1;i--){
    b[c[a[i]]]=a[i];
    c[a[i]]--;
  }
}

int main(){
  int n;
  int i,MAX=0;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
    if(MAX<a[i]) MAX=a[i];
  }

  countingSort(MAX,n);

  for(i=1;i<n;i++) printf("%d ",b[i]);
  printf("%d\n",b[i]);
  return 0;
}
