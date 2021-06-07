#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 20000
#define pi M_PI

int main(){
  int n,q,k=0;
  int a[N],b[N];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
  }
  scanf("%d",&q);
  for(int j=0;j<q;j++){
      scanf("%d",&b[j]);
      for(int i=0;i<n;i++){
          if(b[j]==a[i]){
              k++;
              break;
          }
      }
  }
  printf("%d\n",k);
  return 0;
}
