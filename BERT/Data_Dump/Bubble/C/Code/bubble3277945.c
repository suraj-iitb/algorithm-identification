#include<stdio.h>
void swap(int *,int*);
int main (){
  int N,kar,i,j;
  int b[100];
  int flag = 1;
  int count = 0;
  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&b[i]);
  }
  while(flag != 0){
    flag = 0;
    for(j = N-1;j >= 1;j--){
      if(b[j] < b[j-1]){
	swap(&b[j],&b[j-1]);
	flag = 1;
	count++;
      }
    }
  }
  for(i=0;i<N-1;i++){ /*iは1過ぎている*/
    printf("%d ",b[i]);
  }
  printf("%d\n",b[N-1]);
  printf("%d\n",count);

    
  return 0;
}
void swap(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

