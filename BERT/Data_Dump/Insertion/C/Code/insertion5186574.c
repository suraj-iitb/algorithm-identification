#include<stdio.h>

void exp1(int An[], int N){

  int i;
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",An[i]);
  }
  printf("\n");
}


  void cal(int An[], int N){
    int j,i,e;
    for(i=1;i<N;i++){
      e = An[i];
      j = i-1;
      while(j>=0 &&An[j] > e){
    An[j+1] = An[j];
    j--;
      }

      An[j+1] =e;
      exp1(An,N);
    }
  }

int main(){
  int N,j,i;
  int An[100];

  scanf("%d",&N);
  for(i=0;i<N;i++){

    scanf("%d",&An[i]);

  }

  exp1(An,N);
  cal(An,N);

  return 0;






}

