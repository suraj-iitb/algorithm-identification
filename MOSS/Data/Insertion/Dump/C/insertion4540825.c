#include <stdio.h>
#define N 100

int main(){
    int in[N];
    int num;

    scanf("%d",&num);
    for(int i=0;i<N;i++){
    scanf("%d",&in[i]);
  }
  trace(in,num);
  insertsort(in,num);
  return 0;
}

int trace(int in[],int num){
  int i;
  for(i=0;i<num;i++){
    if(i>0)printf(" ");
    printf("%d",in[i]);
  }
  printf("\n");
}

int insertsort(int in[],int num){
  //swapをするのと一緒。
  int c;
  for(int i=1;i<num;i++){
    int j=i-1;
    int v = in[i];
    while(j>=0 && in[j] > v){
      in[j+1] = in[j];
      j--;
    }
    in[j+1] = v;
    trace(in,num);
  }
}

