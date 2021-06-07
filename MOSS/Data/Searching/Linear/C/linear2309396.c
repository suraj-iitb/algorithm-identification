#include <stdio.h>

int main(){
  int a[10000];
  int b[10000];
  int n,m,i,j,cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&b[i]);
  }
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      if(a[j]==b[i]){
        cnt++;
        break;
      }
      else continue;
    }
  }
  printf("%d\n",cnt);
  return 0;
}
