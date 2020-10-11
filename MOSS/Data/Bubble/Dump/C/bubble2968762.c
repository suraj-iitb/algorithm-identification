#include<stdio.h>
int main(){
  int flag1 = 1;
  int i,N,temp,c=0;
  int argv[100];

  scanf("%d",&N);

  for( i=0 ; i<N ; i++ ){
    scanf("%d",&argv[i]);
  }

  while(flag1){
    flag1 = 0;
    for( i=N-1 ; i>0 ; i-- ){
      if(argv[i] < argv[i-1]){
        temp = argv[i];
        argv[i] = argv[i-1];
        argv[i-1] = temp;
        c++;
        flag1 = 1;
      }
    }
  }

  for( i=0 ; i<N-1 ; i++)
    printf("%d ",argv[i]);

  printf("%d\n",argv[N-1]);
  printf("%d\n",c);

  return 0;
}
