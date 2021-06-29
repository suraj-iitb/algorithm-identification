#include<stdio.h>
#define MAX 10000
int A[MAX];

int LinearSearch(int key,int n){//Aの要素数とkey入れると　あるかどうか判定出来る
  int i=0;
  A[n]=key;//最後に番兵設置 Aの要素はn-1までだから問題ない
  while (A[i] != key)i++;
  
  if (i == n)return 0;//見つからなかった
  return 1;//見つかった
}

int main(){
  int i;
  int n;
  int key_num;
  int key;
  int count=0;//一致した数
  
  scanf("%d",&n);//input
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&key_num);
  
  for(i=0;i<key_num;i++){//Aにkeyがあるか
    scanf("%d",&key);
    if(LinearSearch(key,n)==1)count++;
  }
  
  printf("%d\n",count);
  return 0;
}
/*
  数字の数
  数　数　数A
  確かめるkeyの数
  key　key　keyT

  出力
  TのうちAの中にある数
*/

