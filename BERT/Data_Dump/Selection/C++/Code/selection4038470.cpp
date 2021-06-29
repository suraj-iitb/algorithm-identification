#include<stdio.h>

#define N 100

int main(){
  int sel[N];
  int i,j,temp,minj,cnt=0,num;

  scanf("%d",&num);

  for(i=0;i<num;i++){
    scanf("%d",&sel[i]);
  }

  for(i=0;i<num;i++){
    minj = i;
    for(j=i;j<num;j++){
      if(sel[j] < sel[minj]){	
	minj = j;
      }     
    }
    //sel[i] と sel[minj]を交換
    temp = sel[i];
    sel[i] = sel[minj];
    sel[minj] = temp;
    if (minj!=i) cnt++;
  }

  for(i=0;i<num;i++){
    if(i) printf(" ");
    printf("%d",sel[i]);
  }

  printf("\n%d\n",cnt);

  return 0;
}

