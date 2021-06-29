#include<stdio.h>
#define NOT_FOUND 0
int linerSerch(int n,int *a,int key){
  int i = 0;
  a[n] = key;
  while(a[i] != key){
    i++;
  }
  if(i == n) return NOT_FOUND;
  return 1;
}
int main(){
  int n,a[10000],q,b[500],i,cnt = 0;
  scanf("%d",&n);
  for(i = 0;i < n; i++){
     scanf("%d",&a[i]);
   }
   scanf("%d",&q);
   for(i = 0;i < q; i++){
     scanf("%d",&b[i]);
   }
   for(i = 0;i < q; i++){
     if(linerSerch(n,a,b[i]) != NOT_FOUND) cnt++;
   }
   printf("%d\n",cnt);
   return 0;
 }

