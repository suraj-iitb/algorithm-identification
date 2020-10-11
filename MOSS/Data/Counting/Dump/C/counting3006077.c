#include<stdio.h>
#include<stdlib.h>

#define max 2000001
#define maxvalue 10000


int main(){
  unsigned short *Aarray,*Barray;

  int Carray[maxvalue + 1];
  int num,j,i;

  scanf("%d",&num);

  Aarray = malloc(sizeof(short) * num + 1);
  Barray = malloc(sizeof(short) * num + 1);

  for(i = 0;i < maxvalue;i++){
    Carray[i] = 0;
  }
  for(i = 0;i < num;i++){
    scanf("%hu",&Aarray[i + 1]);
    Carray[Aarray[i + 1]]++;
  }
  for(i = 1;i <= maxvalue;i++){
    Carray[i] = Carray[i] + Carray[i - 1];
  }
  for(j = 1;j <= num;j++){
    Barray[Carray[Aarray[j]]] = Aarray[j];
    Carray[Aarray[j]]--;
  }
  for(i = 1;i <= num;i++){
    if(i > 1){
      printf(" ");
    }
    printf("%d",Barray[i]);
  }
  printf("\n");
  return 0;
}

