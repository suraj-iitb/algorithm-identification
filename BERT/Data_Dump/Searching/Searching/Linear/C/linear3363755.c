#include<stdio.h>
int LinearSearch(int,int,int);

int main(){
  int n,q,i,key,result=0;
  int s[10000+1];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&key);//配列tのi番目の値をkeyとしてsのi番目?最後までの値と比較する
    if(LinerSearch(s,n,key)!=0) result++;
  }
  printf("%d\n",result);
  return 0;
}

int LinerSearch(int s[],int n,int key){
  int i=0;
  s[n]=key;
  while(s[i]!=key){
    i++;
  }
  if(i==n){
    return 0;
  }
  return 1;//iとnが同値でないときiをreturnし、同値なとき0をreturnする。nは番兵なのでi=nになってはいけない
}

  


