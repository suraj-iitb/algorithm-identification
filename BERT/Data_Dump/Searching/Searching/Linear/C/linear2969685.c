#include<stdio.h>
int LS(int X[], int n, int key){
  int i=0;
  while(i<n){
    if(X[i]==key)return 1;
    i++;
  }
  return 0;
}
int main(){
  int i, n, q, key, ans=0;
  int Y[10001];

  scanf("%d", &n);
  for(i=0 ; i<n ; i++){
    scanf("%d", &Y[i]);
  }
  scanf("%d", &q);
  for(i=0 ; i<q ; i++){
    scanf("%d", &key);
    if(LS(Y, n, key)==1)ans++;
  }
  printf("%d\n",ans);
  return 0;
}
