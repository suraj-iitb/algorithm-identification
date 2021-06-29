#include <stdio.h>
#define A 100

int main(){
  int i,num,in[A],j,temp;
  int cnt = 0;

  scanf("%d",&num);

  for(i=0;i<num;i++){
    scanf("%d",&in[i]);
  }

  for(i=0;i<num-1;i++){
    for(j=num-1;j>i;j--){
      if(in[j-1] > in[j]){
	temp = in[j];
	in[j] = in[j-1];
	in[j-1] = temp;
	cnt++;
      }
    }
     printf("%d ",in[i]);
  }
  printf("%d\n%d\n",in[num-1],cnt);
  return 0;
}

