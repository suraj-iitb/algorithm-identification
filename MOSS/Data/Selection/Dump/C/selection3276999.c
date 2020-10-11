#include <stdio.h>

int selectionsort(int a[],int n){
  int i,j,minj,cnt=0,tmp;
  int flag=0;
  for(i=0;i<n;i++){
    minj = i;
    flag = 0;
    for(j=i;j<n;j++){
      if(a[j] < a[minj]){
        minj = j;
        flag++;
      }
    }
      if(flag >= 1){
        tmp = a[i];
        a[i] = a[minj];
        a[minj] = tmp;
        cnt++;
      }
    }
  return cnt;
}

int main(){
  int a[110];
  int i,n,cnt;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  cnt = selectionsort(a,n);
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}

