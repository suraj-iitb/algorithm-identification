#include <stdio.h>

int main (){

  int num, nums, i, j, cnt=0;

  scanf("%d", &num);

  int n[num];

  for(i=0; i<num; i++){

    scanf("%d", &n[i]);
    
  }

  for(i=0; i<num; i++){

    for(j=num-1; j>i; j--)
      if(n[j] < n[j-1]){
	nums = n[j];
	n[j]=n[j-1];
	n[j-1]=nums;
	cnt++;
      }

  }

  for(i=0;i<num;i++){
    if(i>0)printf(" ");
    printf("%d", n[i]);
    if(i==num-1)printf("\n");
  }
  printf("%d\n",cnt);

  return 0;
  
}
