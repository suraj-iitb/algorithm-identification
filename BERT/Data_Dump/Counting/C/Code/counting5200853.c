#include<stdio.h>
#include<stdlib.h>

#define MAX 10000

int main(){
  int i,k,n,c[MAX+1];

  scanf("%d",&n);

  unsigned short *a, *b;

  a=malloc(sizeof(short)*n+1);
  b=malloc(sizeof(short)*n+1);

  scanf("%hd",&a[0]);
  k=a[0];//一番最初に入力された数字をkに入れる
  for(i=1;i<n;i++){
    scanf("%hd",&a[i]);
    if(k<a[i])k=a[i];//kよりも大きかったらkに入れる（最終的にkが最大値になる）
  }
  for(i=0;i<=k;i++)
    c[i]=0;//c[0]-c[5]まで０を入れる（数字の種類数分の配列を作る＜例＞最大値が６だったら０から６までの配列を作る）

  for(i=0;i<n;i++)
    c[a[i]]++;//cに数字の数をカウントしていく（０が３個あったら最終的にc[0]＝３となる）

  for(i=1;i<=k;i++)
    c[i]=c[i]+c[i-1];//大きさがいっこ前の数の個数を足していく（例： C[1](１の個数)にc[0](０の個数)をたす）

  for(i=n;i>=0;i--){//
    b[c[a[i]]]=a[i];
    c[a[i]]--;
  }
  for(i=1;i<=n;i++){
    printf("%d",b[i]);
    if(i<n)printf(" ");
  }
  printf("\n");
  return 0;
}

