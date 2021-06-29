#include<stdio.h>
int main(){
  int N,i,j,temp,mini,count=0;
  int argv[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&argv[i]);
  }
  for(i=0;i<=N-1;i++){
    mini=i;
    for(j=i;j<=N-1;j++){
      if(argv[j]<argv[mini]){
        mini=j;
      }
    }
      if(i != mini){
        count++;
        temp=argv[i];
        argv[i]=argv[mini];
        argv[mini]=temp;
      }}
    for(i=0;i<N-1;i++){
      printf("%d ",argv[i]);

        }
    printf("%d\n",argv[N-1]);
    printf("%d\n",count);
    return 0;
}
