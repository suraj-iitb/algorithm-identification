
#include<stdio.h>

int main(){
  int i,j,k,s,numA,numB,num=0;
  scanf("%d",&numA);

  int retuA[numA];

  for(i = 0; i < numA; i++){
    scanf("%d",&retuA[i]);
  }

  scanf("%d",&numB);

  int retuB[numB];

  for(i = 0; i < numB; i++){
    scanf("%d",&retuB[i]);
  }

  for(i = 0; i < numB; i++){
    for(j = 0; j < numA; j++){
      if(retuA[j]==retuB[i]){
	num++;
	break;
      }
    }
  }
  printf("%d\n",num);
  return 0;
}
