#include <stdio.h>

#define N 100001
struct sas{
  int num;
  char character;
  int key;
};

struct sas array[N]; 

int DefPar(int,int); 
void DefQuick(int,int);

int main(){
  char cha1,cha2,cha3;
  int n;
  int i,numa;
int numb = 0;
  scanf("%d%c",&n,&cha1);
  for(i = 0;i < n;i++){

    scanf("%c%c%d%c",&array[i].character,&cha2,&array[i].num,&cha3);

    array[i].key = i;
  }
  numa = DefPar(0,n - 1);

  DefQuick(0,n - 1);

  for(i = 0;i < n;i++){

    if(array[i].key > array[i+1].key && array[i].num == array[i+1].num){

     numb = 1;

      break;
    }
  }
  if(numb == 0) printf("Stable\n");

  if(numb == 1) printf("Not stable\n");

  for(i = 0;i < n;i++){
    printf("%c %d\n",array[i].character,array[i].num);
  }
  return 0;
}
 
int DefPar(int a,int b){
  int i,j;
  struct sas numx,tmp;
  numx.num = array[b].num;
  i = a - 1;
  for(j = a;j < b;j++){
    if(array[j].num <= numx.num){
      i = i + 1;
      tmp = array[i];
      array[i] = array[j];
      array[j] = tmp;
    }
  }
  tmp = array[i+1];

  array[i + 1] = array[b];

  array[b] = tmp;

  return i + 1;
}
 
void DefQuick(int a,int b){
  int numq;
  if(a < b){
    numq = DefPar(a,b);
    DefQuick(a,numq - 1);
    DefQuick(numq + 1,b);
  }
}
