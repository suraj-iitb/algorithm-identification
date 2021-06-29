#include <stdio.h>
#define N 100

int main(){
  int i,bubble[N],a,j,cnt=0;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&bubble[i]);
  }
  for(j=0;j<a;j++){
    for(i=a-1;i>=j+1;i--){
      if(bubble[i]<bubble[i-1]){
	int c=bubble[i];
	bubble[i]=bubble[i-1];
	bubble[i-1]=c;
	cnt++;
      }
    }
  }
  for(i=0;i<a;i++){
    printf("%d",bubble[i]);
    if(i!=a-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}

