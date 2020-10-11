#include<stdio.h>

void insertion(int N,int a[]);

int main(void){
  int N,s;
  scanf("%d",&N);
  if(1<=N||N<=100){
    int a[N];
    for(s=0;s<N;s++){
      scanf("%d",&a[s]);
      printf("%d",a[s]);
      s==N-1?printf("\n"):printf(" ");
    }
    insertion(N,a);
  }
  return 0;
}

void insertion(int N,int a[]){
  int i,j,k,key;
  for(i=1;i<N;i++){
    key=a[i];
    j=i-1;
    while(j>=0&&a[j]>key){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=key;
    for(k=0;k<N-1;k++){
      printf("%d ",a[k]);
    }
    printf("%d\n",a[N-1]);
  }
}
