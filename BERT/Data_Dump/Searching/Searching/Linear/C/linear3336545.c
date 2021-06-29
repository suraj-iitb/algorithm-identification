#include<stdio.h>
#define MAX 10001
int main(){
  int datanum,datanum2,i,j;
  int a[MAX];
  int b[MAX];
  int ans = 0;
  scanf("%d",&datanum);
  for(i=0;i<datanum;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&datanum2);
  for(i=0;i<datanum2;i++){
    scanf("%d",&b[i]);
  }

  for(i=0;i<datanum2;i++)
    for(j=0;j<datanum;j++){
      if(a[j] == b[i]){
	ans++;
	break;
      }
    }
  printf("%d\n",ans);
  return 0;
}

