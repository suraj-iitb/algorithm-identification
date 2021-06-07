#include<stdio.h>

#define N 100000

int Search(int *,int ,int);

int main(){
  int loop1,loop2;
  int retu1[N],retu2;
  int i,count=0;
 
  scanf("%d",&loop1);
  for(i=0;i<loop1;i++){
    scanf(" %d",&retu1[i]);
  }

  scanf("%d",&loop2);
  for(i=0;i<loop2;i++){
    scanf(" %d",&retu2);
    count+=Search(retu1,retu2,loop1);
  }

  printf("%d\n",count);
  return 0;
}


int Search(int *x,int y,int length){
  int side1=0;
  int side2=length;
  int center=0;

  while(1){
    if(side1>=side2)break;
    center=(side1+side2)/2;
    if(x[center]==y){
      return 1;
    }

    else if(x[center]>y){
      side2=center;
    }

    else if(x[center]<y){
      side1=center+1;
    }
  } 
  return 0;
}

