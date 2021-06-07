#include <stdio.h>

#define N 10000

int main(){

  int n1,n2,i,j,cnt=0,a[N],b[N];
  //入力
  
  scanf("%d",&n1);

  for(i=0;i<n1;++i){
    scanf("%d",&a[i]);
  }

  scanf("%d",&n2);
  
  for(i=0;i<n2;i++){
    scanf(" %d",&b[i]);
  }


  //探査
  for(i=0;i<n2;i++){
    for(j=0;j<n1;++j){
      if(b[i]==a[j]){
	cnt++;
	break;
      }
    }
  }
 
  //表示

  printf("%d\n",cnt);

  return 0;

}

