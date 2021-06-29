#include<stdio.h>
int main(){
  int i;
  int j;
  int n;
  int a[100];
  int count=0;
  int minj;
  int tmp;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n-1;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(a[j] < a[minj]) minj = j;
    }
    if(a[i] != a[minj]){
      tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
      count++;
    }
  }

  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i != n-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}

