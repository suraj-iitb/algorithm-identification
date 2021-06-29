#include<stdio.h>
#define N 101
 
void print(int *a, int n){
  int i;
  for(i=0;i<n;i++){
    if(i) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
}
 
void insertionsort(int *a, int n){
  int i,j,key;
 
  for(i=1;i<n;i++){    //０の時は前に数字がないので、１からスタート
    key=a[i];
    j=i-1;
    while(j>=0&&key<a[j]){  //前の数字より大きい時点で、最大なので移動はしない
      a[j+1]=a[j];
      j--;           //大きい方を前に、小さい方を後ろに移動させる
      a[j+1]=key;
    }
    print(a,n);  //表示
  }
}
 
int main(){
  int i,n,a[N];
 
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
 
  print(a,n);
  insertionsort(a,n);
 
  return 0;
}
