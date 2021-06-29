#include<stdio.h>
void print(int*,int);
int main(){
  int N,i,j,b,a[100];
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&a[i]);
  print(a,N);
  for(i=1;i<N;i++){
    b=a[i];
    j=i-1;
    while(j>=0&&a[j]>b){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=b;
    print(a,N);
  }
  return 0;
}
void print(int *a,int N){
    int i;
    for(i=0;i<N;i++){
        if(i>0)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}


