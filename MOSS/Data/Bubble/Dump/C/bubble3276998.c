#include <stdio.h>

int bubbleSort(int a[],int n){
  int i,j,tmp,cnt=0;
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(a[j-1] > a[j]){
        tmp = a[j];
        a[j] = a[j-1];
        a[j-1] = tmp;
        cnt++;
      }
    }
  }
  return cnt;
}

int main(){
  int cnt;
  int a[110];
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  cnt = bubbleSort(a,n);
  for(i=0;i<n;i++) {
    printf("%d",a[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}

