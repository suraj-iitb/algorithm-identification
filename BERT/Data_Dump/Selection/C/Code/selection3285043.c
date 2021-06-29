#include<stdio.h>
#include<stdlib.h>
int cnt;
int main(){
  int *a,i,j,x,minj,temp,cnt=0;
  scanf("%d",&x);
  a=malloc(sizeof(int)*(x+1));
  for(i=0;i<x;i++){
    scanf("%d",&a[i]);
  }
  // 選択ソート
  for(i=0;i<x-1;i++){
    minj=i;//配列の先頭を最小値の要素とする
    //printf("%d\n",i);
    //最小値の添字の更新
    for(j=i+1;j<x;j++){
	if(a[j]<a[minj]){
            minj=j;
	}
    }
    //最小値と先頭要素の交換
      if(minj!=i){
      temp = a[i];
      a[i] = a[minj];
      a[minj] = temp;
      cnt++;
      }
    //printf("aaaaaaaaaa\n");
  }
  //if(cnt==(x/2)+1)cnt=0;
  //表示
  for(i=0;i<x-1;i++){
  printf("%d ",a[i]);
  }
  printf("%d\n",a[x-1]);
  //printf("aaaaa\n");
  printf("%d\n",cnt);
  //printf("aaaaa\n");
  return 0;
}

